import os
import shutil

folders = ['C.A.','C.M.A.','C.P.','Const.P.','Crl.A.','Crl.P.']
judgdetails = {}

with open("judgementsDetails.txt", "w", encoding="utf-8") as f:
    f.write(f"Category\t S. No.\t Abstract of Judgement\n")
    with open("Judgements Details.txt", "r", encoding="utf-8") as file:
        next(file)
        for line in file:
            catogary, index, detail = line.strip().split("\t\t")
            if catogary == "C.A.":
                detail = "CA"+index+'-----'+detail
            elif catogary == "C.M.A.":
                detail = "CMA"+index+'-----'+detail
            elif catogary == "C.P.":
                detail = "CP"+index+'-----'+detail
            elif catogary == "Const.P.":
                detail = "CONSTP"+index+'-----'+detail
            elif catogary == "Crl.A.":
                detail = "CRLA"+index+'-----'+detail
            elif catogary == "Crl.P.":
                detail = "CRLP"+index+'-----'+detail
            f.write(f"{catogary}\t\t{index}\t\t{detail}\n")    