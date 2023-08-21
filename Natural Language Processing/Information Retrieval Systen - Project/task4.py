import random

def readDocumentTermFrequencies(filePath):
    documentTermFrequencies = {}
    with open(filePath, "r", encoding="utf8") as file:
        for line in file:
            parts = line.strip().split()
            termId = int(parts[0])
            documentFrequencies = {}
            for documentFrequencyPart in parts[1:]:
                document_id, frequency = documentFrequencyPart.split(":")
                documentFrequencies[document_id] = float(frequency)
            documentTermFrequencies[termId] = documentFrequencies
    return documentTermFrequencies

def getTopTerms(termFrequencies):
    termFrequencySums = {}
    for termId, documentFrequencies in termFrequencies.items():
        termFrequencySums[termId] = sum(documentFrequencies.values())
    sortedTermIds = sorted(termFrequencySums, key=termFrequencySums.get, reverse=True)[:10]
    return sortedTermIds

def readVocabulary(filePath):
    vocabulary = {}
    with open(filePath, "r", encoding="utf8") as file:
        for line in file:
            parts = line.strip().split()
            termId = int(parts[0])
            term = parts[1]
            vocabulary[termId] = term
    return vocabulary

def createQueries(terms, numQueries, numTermsPerQuery):
    queries = []
    for i in range(numQueries):
        queryTerms = random.sample(terms, numTermsPerQuery)
        query = " ".join(queryTerms)
        queries.append(query)
    return queries

def createBenchmark(tfidfFile, bm25File, vocabularyFile):
    tfidfTermFrequencies = readDocumentTermFrequencies(tfidfFile)
    bm25TermFrequencies = readDocumentTermFrequencies(bm25File)
    vocabulary = readVocabulary(vocabularyFile)

    topTfidfTerms = getTopTerms(tfidfTermFrequencies)
    topBm25Terms = getTopTerms(bm25TermFrequencies)

    tfidfTerms = [vocabulary[termId] for termId in topTfidfTerms]
    bm25Terms = [vocabulary[termId] for termId in topBm25Terms]

    twoTermQueries = createQueries(tfidfTerms, 5, 2)
    threeTermQueries = createQueries(bm25Terms, 5, 3)

    benchmark = twoTermQueries + threeTermQueries
    return benchmark

def writeBenchmarkToFile(benchmark, filePath):
    with open(filePath, "w", encoding="utf8") as file:
        file.write("Q_No.\tQuery\n")
        for i, query in enumerate(benchmark):
            file.write(f"{i+1}\t{query}\n")

if __name__ == "__main__":
    tfidfFile = "tfIdfWeighting.txt"
    bm25File = "bm25Weighting.txt"
    vocabularyFile = "Extracted_Vocabulary.txt"

    benchmark = createBenchmark(tfidfFile, bm25File, vocabularyFile)

    writeBenchmarkToFile(benchmark, "benchmarkFile.txt")