import os
import re
import string
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize
from collections import defaultdict
import math
import PyPDF2

vocabulary = {}
with open("Extracted_Vocabulary.txt", 'r', encoding="utf8") as f:
    for line in f:
        index, term = line.strip().split()
        vocabulary[term] = int(index)

documentIDs = {}
with open("indexedDocuments.txt", 'r', encoding="utf8") as f:
    next(f)
    for line in f:
        catogary, index, docname = line.strip().split("\t\t")
        doc = docname.split('-----')
        documentIDs[docname] = doc[0]

documents = {}
docIndex = 0


pattern = re.compile(r'\W+', re.UNICODE)
stemmer = PorterStemmer()
lemmatizer = WordNetLemmatizer()
stopWords = set(stopwords.words('english'))
invertedIndex = defaultdict(dict)
rawtermfreq = {}

folders = ['C.A.','C.M.A.','C.P.','Const.P.','Crl.A.','Crl.P.']

for folderName in folders:
    for fileName in os.listdir(folderName):
        try:
            with open(os.path.join(folderName, fileName), 'rb') as pdfFile:
                pdfReader = PyPDF2.PdfReader(pdfFile)
                text = ""
                for pageNum in range(len(pdfReader.pages)):
                    try:
                        text += pdfReader.pages[pageNum].extract_text()
                    except:
                        continue
            print(fileName, 'being read')
            text = text.lower()                       
            text = pattern.sub(' ', text)             
            tokens = word_tokenize(text)                
            tokens = [t for t in tokens if len(t) > 2]  
            tokens = [t for t in tokens if t not in stopWords] 
            tokens = [lemmatizer.lemmatize(t) for t in tokens] 
            tokens = [stemmer.stem(t) for t in tokens]  
            
            docId = documentIDs[fileName]
            termFreq = {}
            for token in tokens:
                if token in vocabulary:
                    termIndex = vocabulary[token]
                    if termIndex in termFreq:
                        termFreq[termIndex] += 1
                    else:
                        termFreq[termIndex] = 1
            
            rawtermfreq[docId] = termFreq
            
        except:
            print(f"{fileName}")
            continue

rawfreq = {}
for term, index in sorted(vocabulary.items(), key=lambda x: x[1]):
    termDict = {}
    for docId, freqDict in sorted(rawtermfreq.items()):
        if index in freqDict:
            termFreq = freqDict[index]
            termDict[docId] = termFreq
    if termDict:
        rawfreq[index] = termDict
    
    termDict = dict(sorted(termDict.items()))
rawfreq = dict(sorted(rawfreq.items()))

with open('invertedIndex(RTF).txt', 'w') as f:
    for index, termDict in rawfreq.items():
        line = f"{index}"
        for docId, freq in sorted(termDict.items()):
            line += f" {docId}:{freq}"
        f.write(line + "\n")

logtermfreq = {}
for term, index in sorted(vocabulary.items(), key=lambda x: x[1]):
    termDict = {}
    for docId, freqDict in sorted(rawtermfreq.items()):
        if index in freqDict:
            termFreq = freqDict[index]
            termDict[docId] = 1 + math.log10(termFreq)
    if termDict:
        logtermfreq[index] = termDict
   
    termDict = dict(sorted(termDict.items()))
logtermfreq = dict(sorted(logtermfreq.items()))

with open('logFrequencyWeighting.txt', 'w') as f:
    for index, termDict in logtermfreq.items():
        line = f"{index}"
        for docId, freq in sorted(termDict.items()):
            line += f" {docId}:{freq}"
        f.write(line + "\n")

numDocs = 1047
idf = {}
for termId, docFreqs in rawfreq.items():
    df = len(docFreqs)
    idf[termId] = math.log10(numDocs/df)

tfidf = {}
for termId, docFreqs in rawfreq.items():
    for docId, raw_freq in docFreqs.items():
        tf = logtermfreq[termId][docId]
        tfidfVal = tf * idf[termId] 
        if termId not in tfidf:
            tfidf[termId] = {}
        tfidf[termId][docId] = tfidfVal

with open('idfWeighting.txt', 'w') as f:
    for index, idfvalue in idf.items():
        f.write('{} {}\n'.format(index, idfvalue))

with open('tfidfWeighting.txt', 'w') as f:
    for index, termDict in tfidf.items():
        line = f"{index}"
        for docId, freq in sorted(termDict.items()):
            line += f" {docId}:{freq}"
        f.write(line + "\n")

bm25weight = {}
k = 0.5
for termindex, docfreq in rawfreq.items():
        for docid, freqofterm in docfreq.items():
            bm25 = ((k+1) * int(freqofterm)) / (int(freqofterm) + k)
            bm25 = bm25 * idf[termindex]
            if termindex not in bm25weight:
                bm25weight[termindex] = {}
            bm25weight[termindex][docid] = bm25

with open('bm25Weighting.txt', 'w') as f:
    for index, termDict in bm25weight.items():
        line = f"{index}"
        for docId, freq in sorted(termDict.items()):
            line += f" {docId}:{freq}"
        f.write(line + "\n")