import math
from nltk.tokenize import wordtokenize

def loadtfidfweights(filename):
    tfidf = {}
    with open(filename) as f:
        for line in f:
            parts = line.strip().split()
            termid = int(parts[0])
            tfidf[termid] = {}
            for pair in parts[1:]:
                docid, tfidfval = pair.split(":")
                tfidf[termid][docid] = float(tfidfval)
    return tfidf

def calculatedocnormdict(tfidf):
    docnormdict = {}
    for termid, docdict in tfidf.items():
        for docid, tfidfval in docdict.items():
            if docid not in docnormdict:
                docnormdict[docid] = 0
            docnormdict[docid] += tfidfval ** 2
    for docid, normval in docnormdict.items():
        docnormdict[docid] = math.sqrt(normval)
    return docnormdict

def calculatenormalizedtfidfdict(tfidf, docnormdict):
    normalizedtfidfdict = {}
    for termid, docdict in tfidf.items():
        normalizedtfidfdict[termid] = {}
        for docid, tfidfval in docdict.items():
            normalizedtfidfdict[termid][docid] = tfidfval / docnormdict[docid]
    return normalizedtfidfdict

def writenormalizedtfidfdicttofile(filename, normalizedtfidfdict):
    with open(filename, 'w', encoding="utf8") as f:
        for index, termdict in normalizedtfidfdict.items():
            line = f"{index}"
            for docid, freq in sorted(termdict.items()):
                line += f" {docid}:{freq}"
            f.write(line + "\n")

def loadvocabulary(filename):
    vocab = {}
    with open(filename, 'r', encoding="utf8") as f:
        for line in f:
            index, term = line.strip().split()
            vocab[term] = int(index)
    return vocab

def loadqueries(filename):
    queries = {}
    with open(filename) as f:
        next(f)
        for line in f:
            parts = line.strip().split("\t")
            queryid = int(parts[0])
            querytext = parts[1]
            queries[queryid] = querytext
    return queries

def tokenizequeries(queries):
    tokenizedqueries = {}
    for queryid, querytext in queries.items():
        tokenizedqueries[queryid] = wordtokenize(querytext)
    return tokenizedqueries

def calculatetfqueries(tokenizedqueries, vocab):
    tfqueries = {}
    for queryid, tokens in tokenizedqueries.items():
        tfquery = {}
        for term in tokens:
            termindex = vocab[term]
            if termindex in tfquery:
                tfquery[termindex] += 1
            else:
                tfquery[termindex] = 1
        tfqueries[queryid] = tfquery
    return tfqueries

def calculaterawfreqdict(vocab, tfqueries):
    rawfreq = {}
    for term, index in sorted(vocab.items(), key=lambda x: x[1]):
        termdict = {}
        for queryid, freqdict in sorted(tfqueries.items()):
            if index in freqdict:
                termfreq = freqdict[index]
                termdict[queryid] = termfreq
        if termdict:
            rawfreq[index] = termdict
        termdict = dict(sorted(termdict.items()))
    rawfreq = dict(sorted(rawfreq.items()))
    return rawfreq

def createlogtermfreq(vocab, tfqueries):
    logtermfreq = {}
    for term, index in sorted(vocab.items(), key=lambda x: x[1]):
        termdict = {}
        for queryid, freqdict in sorted(tfqueries.items()):
            if index in freqdict:
                termfreq = freqdict[index]
                termdict[queryid] = 1 + math.log10(termfreq)
        if termdict:
            termdict = dict(sorted(termdict.items()))
            logtermfreq[index] = termdict
    logtermfreq = dict(sorted(logtermfreq.items()))
    return logtermfreq

def readidffile(filename):
    idf = {}
    with open(filename, 'r', encoding="utf8") as f:
        for line in f:
            index, value = line.strip().split()
            idf[int(index)] = float(value)
    return idf

def calculatetfidf(rawfreq, logtermfreq, idf):
    tfidfqueries = {}
    for termid, queryfreq in rawfreq.items():
        for queryid, rawfreq in queryfreq.items():
            tf = logtermfreq[termid][queryid] 
            tfidfval = tf * idf[termid] 

            if termid not in tfidfqueries:
                tfidfqueries[termid] = {}
            tfidfqueries[termid][queryid] = tfidfval
    return tfidfqueries

def calculatetfidfsimilarity(tfidfqueries, normalizedtfidfdict):
    querynormdict = {}
    for termid, querydict in tfidfqueries.items():
        for queryid, tfidfqueriesval in querydict.items():
            if queryid not in querynormdict:
                querynormdict[queryid] = 0
            querynormdict[queryid] += tfidfqueriesval ** 2

    for queryid, normval in querynormdict.items():
        querynormdict[queryid] = math.sqrt(normval)

    normalizedtfidfqueriesdict = {}
    for termid, querydict in tfidfqueries.items():
        normalizedtfidfqueriesdict[termid] = {}
        for queryid, tfidfqueriesval in querydict.items():
            normalizedtfidfqueriesdict[termid][queryid] = tfidfqueriesval / querynormdict[queryid]

    queryids = list(set([queryid for termindex in normalizedtfidfqueriesdict for queryid in normalizedtfidfqueriesdict[termindex]]))

    normalizedtfidfqueries = {}

    for termid, querydict in tfidfqueries.items():
        for queryid, tfidfqueriesval in querydict.items():
            if queryid not in normalizedtfidfqueries:
                normalizedtfidfqueries[queryid] = {}
            normalizedtfidfqueries[queryid][termid] = normalizedtfidfqueriesdict[termid][queryid]
    
    docfilenames = {}
    with open("indexedDocuments.txt", 'r', encoding="utf8") as f:
        next(f)
        for line in f:
            catogary, index, docname = line.strip().split("\t\t")
            doc = docname.split('-----')
            docfilenames[doc[0]] = docname

    similarities = {}

    for queryid in queryids:
        similarities[queryid] = {}
        for docid in docfilenames.keys():
            similarities[queryid][docid] = 0

    for queryid, querytfidf in normalizedtfidfqueries.items():
        for termindex, tfidfval in querytfidf.items():
            for docid, tfidfvaldoc in normalizedtfidfdict[termindex].items():
                if docid in docfilenames.keys():
                    similarities[queryid][docid] += tfidfval * tfidfvaldoc

    with open("tfidfSimilarity.txt", "w", encoding="utf8") as f:
        for queryid, docsim in similarities.items():
            f.write("Query Term {}\n".format(queryid))
            f.write("Weighting Scheme: TFIDF\n")
            for docid, similarity in docsim.items():
                f.write("{}\t\t{}\t\t{}\n".format(docid, docfilenames[docid], similarity))
            f.write("\n")

    topsimilarities = {}

    for queryid in similarities:
        docsimilarities = similarities[queryid]
        sorteddocs = sorted(docsimilarities.items(), key=lambda x: x[1], reverse=True)[:10]
        topdocs = {docid: similarity for docid, similarity in sorteddocs}
        topsimilarities[queryid] = topdocs

    with open("top10tfidf.txt", "w", encoding="utf8") as f:
        for queryid, docsim in topsimilarities.items():
            f.write("Query Term {}\n".format(queryid))
            f.write("Weighting Scheme: TFIDF\n")
            for docid, similarity in docsim.items():
                f.write("{}\t\t{}\t\t{}\n".format(docid, docfilenames[docid], similarity))
            f.write("\n")

if __name__ == "_main_":
    tfidf = loadtfidfweights("tfIdfWeighting.txt")
    docnormdict = calculatedocnormdict(tfidf)
    normalizedtfidfdict = calculatenormalizedtfidfdict(tfidf, docnormdict)
    writenormalizedtfidfdicttofile('tfidfNormalFile.txt', normalizedtfidfdict)
    vocab = loadvocabulary('ExtractedVocabulary.txt')
    queries = loadqueries("benchmarkFile.txt")
    tokenizedqueries = tokenizequeries(queries)
    tfqueries = calculatetfqueries(tokenizedqueries, vocab)
    rawfreq = calculaterawfreqdict(vocab, tfqueries)
    logtermfreq = createlogtermfreq(vocab, tfqueries)
    idf = readidffile('idfWeighting.txt')
    tfidfqueries = calculatetfidf(rawfreq, logtermfreq, idf)

    calculatetfidfsimilarity(tfidfqueries, normalizedtfidfdict)