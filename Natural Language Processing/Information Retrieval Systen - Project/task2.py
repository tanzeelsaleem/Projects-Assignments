import os
import re
import string
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer, WordNetLemmatizer
from nltk.tokenize import word_tokenize
from collections import defaultdict

rootDir = "C:/Users/mtanz/Desktop/Assign1/Judgments Details"

vocabulary = defaultdict(int)
documents = {}
docIndex = 0

pattern = re.compile(r'\W+', re.UNICODE)

stemmer = PorterStemmer()
lemmatizer = WordNetLemmatizer()

stop_words = set(stopwords.words('english'))

for folderName in os.listdir(rootDir):
    folderPath = os.path.join(rootDir, folderName)
    
    if os.path.isdir(folderPath):
        docIndex = 0
        
        for fileName in os.listdir(folderPath):
            filePath = os.path.join(folderPath, fileName)
            
            if os.path.isfile(filePath) and fileName.endswith(".pdf"):
                import PyPDF2
                try:
                    with open(filePath, 'rb') as pdfFile:
                        pdfReader = PyPDF2.PdfReader(pdfFile)
                        text = ""
                        for page_num in range(len(pdfReader.pages)):
                            try:
                                text += pdfReader.pages[page_num].extract_text()
                            except:
                                continue

                    text = text.lower()                       
                    text = pattern.sub(' ', text)              
                    tokens = word_tokenize(text)               
                    tokens = [t for t in tokens if len(t) > 2] 
                    tokens = [t for t in tokens if t not in stop_words]  
                    tokens = [lemmatizer.lemmatize(t) for t in tokens]   
                    tokens = [stemmer.stem(t) for t in tokens]
                    
                    for token in tokens:
                        vocabulary[token] += 1
                    
                    docIndex += 1
                    documentName = os.path.splitext(fileName)[0]
                    documents[documentName] = (folderName, docIndex)

                    with open("Indexed_Documents.txt", "a") as f:
                        f.write(f"{folderName}.\t\t{docIndex}\t\t{documentName}.pdf\n")
                except:
                    continue

vocabulary = {k: v for k, v in sorted(vocabulary.items(), key=lambda item: item[1], reverse=True)}
vocabulary = {k: i for i, (k, v) in enumerate(vocabulary.items())}

with open("Extracted_Vocabulary.txt", "w", encoding="utf-8") as f:
    for term, index in vocabulary.items():
        f.write(f"{index}\t{term}\n")