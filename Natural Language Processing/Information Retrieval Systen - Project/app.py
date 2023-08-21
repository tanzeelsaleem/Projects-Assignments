from flask import Flask, rendertemplate, request
import os
import math
import re
import string
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from nltk.stem import PorterStemmer
import json
import matplotlib.pyplot as plt
from wordcloud import WordCloud

foldername = {
        'A':'C.A', 
        'B':'C.M.A',
        'C':'C.P',
        'D':'Const.P',
        'E':'Crl.A',
        'F':'Crl.P'
    }

app = Flask(__name__)

RESULTSPERPAGE = 10

def loadrawtermfrequencies(filepath):
    rawtermfrequencies = {}
    with open(filepath) as f:
        for line in f:
            parts = line.strip().split()
            termid = int(parts[0])
            rawtermfrequencies[termid] = {}
            for pair in parts[1:]:
                docid, rawtermfrequency = pair.split(":")
                rawtermfrequencies[termid][docid] = int(rawtermfrequency)
    return rawtermfrequencies

def loadnormalizedtfidf(filepath):
    normalizedtfidfdict = {}
    with open(filepath) as f:
        for line in f:
            parts = line.strip().split()
            termid = int(parts[0])
            normalizedtfidfdict[termid] = {}
            for pair in parts[1:]:
                docid, normalizedtfidfval = pair.split(":")
                normalizedtfidfdict[termid][docid] = float(normalizedtfidfval)
    return normalizedtfidfdict

def loadvocabulary(filepath):
    vocab = {}
    with open(filepath, 'r', encoding="utf8") as f:
        for line in f:
            index, term = line.strip().split()
            vocab[term] = int(index)
    return vocab

def loaddocumentfilenames(filepath):
    docfilenames = {}
    with open(filepath, 'r', encoding="utf8") as f:
        next(f)
        for line in f:
            category, index, docname = line.strip().split("\t\t")
            doc = docname.split('-----')
            docfilenames[doc[0]] = doc[1]
    return docfilenames

def buildrawtermfrequencies(rawtermfrequencies, docfilenames):
    rtfreq = {}
    for docid in docfilenames.keys():
        rtfreq[docid] = {}

    for termindex, docfreqs in rawtermfrequencies.items():
        for docid, freq in docfreqs.items():
            if docid in docfilenames.keys():
                rtfreq[docid][termindex] = rawtermfrequencies[termindex][docid]
    return rtfreq

def loaddocumentabstracts(filepath):
    docabstracts = {}
    with open(filepath, 'r', encoding="utf8") as f:
        next(f)
        for line in f:
            category, index, docname = line.strip().split("\t\t")
            doc = docname.split('-----')
            docabstracts[doc[0]] = doc[1]
    return docabstracts

def loadidf(filepath):
    idf = {}
    with open(filepath, 'r', encoding="utf8") as f:
        for line in f:
            index, value = line.strip().split()
            idf[int(index)] = float(value)
    return idf

def generatewordcloud(worddict):
    wordcloud = WordCloud(width=800, height=400, backgroundcolor='#f2f2f2').generatefromfrequencies(worddict)
    plt.figure(figsize=(6, 3))
    plt.imshow(wordcloud, interpolation='bilinear')
    plt.axis('off')
    plt.tightlayout(pad=0)
    plt.savefig('static/wordcloud.png')

@app.route("/")
def index():
    return rendertemplate("index.html")

@app.route('/search')
def search():
    querytext = request.args.get('q')
    
    tokens = re.findall(r'\b\w+\b', querytext.lower())
    tokens = [t for t in tokens if t not in string.punctuation and t.isalpha() and len(t) > 3 and t not in stopwords]
    tokens = [lemmatizer.lemmatize(t) for t in tokens]
    tokens = [stemmer.stem(t) for t in tokens]

    tfquery = {}
    for term in tokens:
        termindex = vocab[term]
        if termindex in tfquery:
            tfquery[termindex] += 1
        else:
            tfquery[termindex] = 1

    tfqueries = {}
    tfqueries[1] = tfquery
    rawfreq = {}
    for term, index in sorted(vocab.items(), key=lambda x: x[1]):
        termdict = {}
        for queryid, freqdict in sorted(tfqueries.items()):
            if index in freqdict:
                termfreq = freqdict[index]
                termdict[queryid] = termfreq
        if termdict:
            rawfreq[index] = termdict

    logtermfreq = {}
    for term, index in sorted(vocab.items(), key=lambda x: x[1]):
        termdict = {}
        for queryid, freqdict in sorted(tfqueries.items()):
            if index in freqdict:
                termfreq = freqdict[index]
                termdict[queryid] = 1 + math.log10(termfreq)
        if termdict:
            logtermfreq[index] = termdict


    tfidfqueries = {}
    for termid, queryfreq in rawfreq.items():
        for queryid, rawfreq in queryfreq.items():
            tf = logtermfreq[termid][queryid]
            tfidfval = tf * idf[termid]
            if termid not in tfidfqueries:
                tfidfqueries[termid] = {}
            tfidfqueries[termid][queryid] = tfidfval

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

    queryids = [1]

    normalizedtfidfqueries = {}

    for termid, querydict in tfidfqueries.items():
        for queryid, tfidfqueriesval in querydict.items():
            if queryid not in normalizedtfidfqueries:
                normalizedtfidfqueries[queryid] = {}
            normalizedtfidfqueries[queryid][termid] = normalizedtfidfqueriesdict[termid][queryid]

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

    topdocs = dict(sorted({k: v for k, v in similarities[1].items() if v != 0}.items(), key=lambda x: -x[1]))

    docdetails = []
    for docid, simscore in topdocs.items():
        folderinitial = docid[0]
        fname = foldername[folderinitial]
        parentdir = os.path.abspath(os.path.join(os.getcwd(), os.pardir))
        filepath = os.path.join(parentdir, fname, docfilenames[docid])
        pdflink = f'<a href="file://{filepath}">{docfilenames[docid]}</a>'
        docdetails.append({'id': docid, 'link': pdflink, 'abstract': docabstracts[docid]})
    
    if len(docdetails)>100:
        docdetails = docdetails[:100]
    numresults = len(docdetails)
    numpages = math.ceil(numresults / RESULTSPERPAGE)
    page = request.args.get('page')
    if page:
        page = int(page)
    else:
        page = 1
    startindex = (page - 1) * RESULTSPERPAGE
    endindex = startindex + RESULTSPERPAGE
    results = docdetails[startindex:endindex]

    wordcloud = {}
    for term in vocab.keys():
        wordcloud[term] = 0
    
    for res in results:
        for termindex, freq in rtfreq[res['id']].items():
            wordcloud[list(vocab.keys())[list(vocab.values()).index(termindex)]] += freq * 10
    
    wordcloud = {k: v for k, v in wordcloud.items() if v != 0}

    generatewordcloud(wordcloud)
    return rendertemplate('search.html', query=querytext, results=results, numpages=numpages, currentpage=page, worddict=wordcloud)

if __name__ == "_main_":
    rawtermfrequencies = loadrawtermfrequencies(os.path.dirname(__file__) + "/invertedIndex(RTF).txt")
    normalizedtfidfdict = loadnormalizedtfidf(os.path.dirname(__file__) + "/tfidfNormalFile.txt")
    vocab = loadvocabulary(os.path.dirname(__file__) + '/ExtractedVocabulary.txt')
    lemmatizer = WordNetLemmatizer()
    stemmer = PorterStemmer()
    stopwords = set(stopwords.words('english'))
    docfilenames = loaddocumentfilenames(os.path.dirname(__file__) + '/indexedDocuments.txt')
    rtfreq = buildrawtermfrequencies(rawtermfrequencies, docfilenames)
    docabstracts = loaddocumentabstracts(os.path.dirname(__file__) + '/judgementsDetails.txt')
    idf = loadidf(os.path.dirname(__file__) + '/idfWeighting.txt')

    from waitress import serve
    serve(app, host="0.0.0.0", port=8080)