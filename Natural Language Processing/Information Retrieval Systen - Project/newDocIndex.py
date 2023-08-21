import os
import shutil

folders = ['C.A.','C.M.A.','C.P.','Const.P.','Crl.A.','Crl.P.']
with open("indexedDocuments.txt", "w", encoding="utf-8") as f:
    f.write(f"Category\t\tIndex\t\tDocument Name\n")
    for folder in folders:
        j=1
        for filename in os.listdir(folder):
            f.write(f"{folder}.\t\t{j}\t\t{filename}\n")
            j+=1
        
    