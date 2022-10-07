# Read the top of streamy.py for usage, and see line 23 of this file
from aes import AESCipher
from Crypto.Util.number import bytes_to_long
from Crypto.Util.number import long_to_bytes
import textwrap
import fileinput

def wrap64(string):
    return '\n'.join(textwrap.wrap(string,64))

bitsknownint = 0
prev = None
prevbit = None
bitsknown = ""
combo = {}

for line in fileinput.input():
    if len(line) > 10:
        firstline = line
        if (len(line) % 2 == 0):
            firstline = '0' + line
        continue
    x, y = map(int, line.split())
    hint = ((x - 1) << 7) | (y - 32)
    tryabit = hint & 1
    i = hint >> 1
    combo[i] = tryabit
    print(x, y, hint, tryabit, i, sep=' | ')

for i in combo:
    bitsknown = str(combo[i]) + bitsknown

key = int(bitsknown, 2)
# All you have to do is figure out what YYY and ZZZ should be...
#    if (YYY):
#        ZZZ

#while (len(bitsknown) < 256):
    #i = 255 - len(bitsknown)
    #for tryabit in ['0', '1']:
        #hint = (i << 1) + int(tryabit)
        #bitsknown = str(tryabit) + bitsknown

AESkey = long_to_bytes(key, 32)
aes = AESCipher(AESkey)
print(firstline)
print(len(firstline))
eavesdroppedaes = bytes.fromhex(firstline)
#('088d72fda25863ae81a27ddc286ee8ffef55bdcd0eeee4487fa42cb9c012155e6c38a32d741c68aaa86fda4c9878cbb4')
print('Recovered plaintext is: {}'.format(aes.decrypt(eavesdroppedaes)[:400]))
printme = "{0:b}".format(bitsknownint)
while len(printme) < 256:
    printme = '0' + printme
print(wrap64(printme))

