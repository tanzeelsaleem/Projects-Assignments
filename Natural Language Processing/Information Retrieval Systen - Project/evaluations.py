import re
from collections import Counter

def readfile(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        data = f.read()
    return data

def parsedata(data):
    queries = re.findall(r'Query Term \d+\nWeighting Scheme: (.+?)\n(.+?)\n\n', data, re.DOTALL)
    queryresults = []
    for query in queries:
        weightingscheme = query[0]
        results = query[1].strip().split('\n')
        initials = [result[0] for result in results]
        mostoccurredinitial = Counter(initials).mostcommon(1)[0][0]
        queryresults.append((weightingscheme, initials, mostoccurredinitial))
    return queryresults

def calculatemetrics(queryresults):
    metrics = []
    for queryresult in queryresults:
        weightingscheme = queryresult[0]
        initials = queryresult[1]
        mostoccurredinitial = queryresult[2]
        tp = initials.count(mostoccurredinitial)
        fp = len(initials) - tp
        fn = 10 - tp
        tn = 90 - fp
        p = tp / (tp + fp)
        r = tp / (tp + fn)
        f1 = 2 * p * r / (p + r)
        ap = 0
        numcorrect = 0
        for i in range(len(initials)):
            if initials[i] == mostoccurredinitial:
                numcorrect += 1
                ap += numcorrect / (i + 1)
        if numcorrect > 0:
            ap /= numcorrect
        metrics.append((weightingscheme, p, r, f1, ap))
    return metrics

def writeresults(filename, metrics, map):
    with open(filename, 'w', encoding='utf-8') as f:
        f.write('Query Terms\tWeighting\tP\tR\tF\tAP\n')
        for i, querymetric in enumerate(metrics):
            queryterm = f'QueryTerm-{i+1}'
            weightingscheme = querymetric[0]
            p = querymetric[1]
            r = querymetric[2]
            f1 = querymetric[3]
            ap = querymetric[4]
            f.write(f'{queryterm}\t{weightingscheme}\t\t{p:.3f}\t{r:.3f}\t{f1:.3f}\t{ap:.3f}\n')
        f.write(f'Mean Average Precision for 10 queries = {map:.3f}')

data = readfile('top10tfidf.txt')
queryresults = parsedata(data)
metrics = calculatemetrics(queryresults)
map = sum(metric[4] for metric in metrics) / len(metrics)
writeresults('tfidfResults.txt', metrics, map)

data = readfile('top10bm25.txt')
queryresults = parsedata(data)
metrics = calculatemetrics(queryresults)
map = sum(metric[4] for metric in metrics) / len(metrics)
writeresults('bm25Results.txt', metrics, map)