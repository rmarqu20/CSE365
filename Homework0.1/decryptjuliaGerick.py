import string

file = open('secretfile.txt.gz.enc','rb')

fileout = open('juliaplaintext.txt.gz','wb')  # you can call this 'secretfile.txt.gz'

def rRot(n,d): return ((n >> d) | (n << (8 - d)))&0xff

byteCount = 0

key = "JggAARsbnnMq" #Change Key
keyBytes = bytes(key,'utf-8')

while 1:
    byteEnc = file.read(1)
    byteKey = keyBytes[byteCount:byteCount + 1]

    # print(byteEnc) # my test
    # print(byteKey) # my test

    if not byteEnc:
        break

    byteXOR = bytes([byteEnc[0] ^ byteKey[0]])
    
    byteWrite = bytes([rRot(byteXOR[0],3)]) #Change Rotate Number
    print(byteWrite)
    fileout.write(byteWrite)
    
    byteCount += 1
    if byteCount > len(keyBytes) - 1:
        byteCount = 0

file.close
fileout.close