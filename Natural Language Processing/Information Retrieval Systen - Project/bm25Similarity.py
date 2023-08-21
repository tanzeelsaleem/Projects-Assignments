import math
from nltk.tokenize import wordtokenize

def loadbm25weights(filename):
    bm25 = {}
    with open(filename) as f:
        for line in f:
            parts = line.strip().split()
            termid = int(parts[0])
            bm25[termid] = {}
            for pair in parts[1:]:
                docid, bm25val = pair.split(":")
                bm25[termid][docid] = float(bm25val)
    return bm25

def calculatedocnormdict(bm25):
    docnormdict = {}
    for termid, docdict in bm25.items():
        for docid, bm25val in docdict.items():
            if docid not in docnormdict:
                docnormdict[docid] = 0
            docnormdict[docid] += bm25val ** 2
    for docid, normval in docnormdict.items():
        docnormdict[docid] = math.sqrt(normval)
    return docnormdict

def calculatenormalizedbm25dict(bm25, docnormdict):
    normalizedbm25dict = {}
    for termid, docdict in bm25.items():
        normalizedbm25dict[termid] = {}
        for docid, bm25val in docdict.items():
            normalizedbm25dict[termid][docid] = bm25val / docnormdict[docid]
    return normalizedbm25dict

def writenormalizedbm25dicttofile(filename, normalizedbm25dict):
    with open(filename, 'w', encoding="utf8") as f:
        for index, termdict in normalizedbm25dict.items():
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

def calculatebm25similarity(rawfreq, normalizedbm25dict):
    querynormdict = {}
    for termid, querydict in rawfreq.items():
        for queryid, bm25queriesval in querydict.items():
            if queryid not in querynormdict:
                querynormdict[queryid] = 0
            querynormdict[queryid] += bm25queriesval ** 2

    for queryid, normval in querynormdict.items():
        querynormdict[queryid] = math.sqrt(normval)

    normalizedbm25queriesdict = {}
    for termid, querydict in rawfreq.items():
        normalizedbm25queriesdict[termid] = {}
        for queryid, bm25queriesval in querydict.items():
            normalizedbm25queriesdict[termid][queryid] = bm25queriesval / querynormdict[queryid]

    queryids = list(set([queryid for termindex in normalizedbm25queriesdict for queryid in normalizedbm25queriesdict[termindex]]))

    normalizedbm25queries = {}

    for termid, querydict in rawfreq.items():
        for queryid, bm25queriesval in querydict.items():
            if queryid not in normalizedbm25queries:
                normalizedbm25queries[queryid] = {}
            normalizedbm25queries[queryid][termid] = normalizedbm25queriesdict[termid][queryid]
    
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

    for queryid, querybm25 in normalizedbm25queries.items():
        for termindex, bm25val in querybm25.items():
            for docid, tfidfvaldoc in normalizedbm25dict[termindex].items():
                if docid in docfilenames.keys():
                    similarities[queryid][docid] += bm25val * tfidfvaldoc

    with open("bm25Similarity.txt", "w", encoding="utf8") as f:
        for queryid, docsim in similarities.items():
            f.write("Query Term {}\n".format(queryid))
            f.write("Weighting Scheme: BM25\n")
            for docid, similarity in docsim.items():
                f.write("{}\t\t{}\t\t{}\n".format(docid, docfilenames[docid], similarity))
            f.write("\n")

    topsimilarities = {}

    for queryid in similarities:
        docsimilarities = similarities[queryid]
        sorteddocs = sorted(docsimilarities.items(), key=lambda x: x[1], reverse=True)[:10]
        topdocs = {docid: similarity for docid, similarity in sorteddocs}
        topsimilarities[queryid] = topdocs

    with open("top10bm25.txt", "w", encoding="utf8") as f:
        for queryid, docsim in topsimilarities.items():
            f.write("Query Term {}\n".format(queryid))
            f.write("Weighting Scheme: BM25\n")
            for docid, similarity in docsim.items():
                f.write("{}\t\t{}\t\t{}\n".format(docid, docfilenames[docid], similarity))
            f.write("\n")

if __name__ == "_main_":
    bm25 = loadbm25weights("bm25Weighting.txt")
    docnormdict = calculatedocnormdict(bm25)
    normalizedbm25dict = calculatenormalizedbm25dict(bm25, docnormdict)
    writenormalizedbm25dicttofile('bm25NormalFile.txt', normalizedbm25dict)
    vocab = loadvocabulary('ExtractedVocabulary.txt')
    queries = loadqueries("benchmarkFile.txt")
    tokenizedqueries = tokenizequeries(queries)
    tfqueries = calculatetfqueries(tokenizedqueries, vocab)
    rawfreq = calculaterawfreqdict(vocab, tfqueries)

    calculatebm25similarity(rawfreq, normalizedbm25dict)