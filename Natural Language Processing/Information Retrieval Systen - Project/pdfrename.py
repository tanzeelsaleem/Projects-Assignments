import os
import shutil

folders = ['C.A.','C.M.A.','C.P.','Const.P.','Crl.A.','Crl.P.']
i=0
for folder in folders:
    j=0
    for filename in os.listdir(folder):
        j+=1
        if i==0:
            newname = "CA"
        elif i==1:
            newname = 'CMA'
        elif i==2:
            newname = 'CP'
        elif i==3:
            newname = 'CONSTP'
        elif i==4:
            newname = 'CRLA'
        else:
            newname = 'CRLP'
        newfilename = newname + str(j)+'-----' + filename
        newpath = os.path.join(folder, newfilename)        
        oldpath = os.path.join(folder, filename)
        shutil.move(oldpath, newpath)
        print(f'Renamed {filename} to {newfilename}')
    i+=1