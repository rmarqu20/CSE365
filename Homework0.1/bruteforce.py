import string

file = open('secretfile.txt.gz.enc', 'rb')


def rightRotate(n, d):  # rotates byte 'n' by 'd' bits
    return ((n >> d) | (n << (8 - d))) & 0xff


key = ''
index = 0
rotation = 1

lower_alphabet = "abcdefghijklmnopqrstuvwxyz"
upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# loads encrypted byte
# doing 'byteEnc = file.read(1)' moves the "pointer" so if you
# want to load byte 4, you need to uncomment everything beforehand
# bytes 1-10 are .gz header bytes
# bytes 12-20 are the file name aka "secretfile.txt"

byteEnc = file.read(1)  # byte 1
# byteEnc = file.read(1)  # byte 2
# byteEnc = file.read(1)  # byte 3
# byteEnc = file.read(1)  # byte 4
# byteEnc = file.read(1)  # byte 5
# byteEnc = file.read(1)  # byte 6
# byteEnc = file.read(1)  # byte 7
# byteEnc = file.read(1)  # byte 8
# byteEnc = file.read(1)  # byte 9
# byteEnc = file.read(1)  # byte 10
# byteEnc = file.read(1)  # byte 11
# byteEnc = file.read(1)  # byte 12
# byteEnc = file.read(1)  # byte 13
# byteEnc = file.read(1)  # byte 14
# byteEnc = file.read(1)  # byte 15
# byteEnc = file.read(1)  # byte 16
# byteEnc = file.read(1)  # byte 17
# byteEnc = file.read(1)  # byte 18
# byteEnc = file.read(1)  # byte 19
# byteEnc = file.read(1)  # byte 20

while rotation != 8:  # for all possible bit rotations 1-7 (8bits in a byte)
    while index != 26:  # for every letter in lowercase alphabet
        key = lower_alphabet[index]  # sets letter as key
        keyBytes = bytes(key, 'utf-8')  # formats the letter into a byte

        byteKey = keyBytes[0:1]  # idk pointless when checking single letter keys

        byteXOR = bytes([byteEnc[0] ^ byteKey[0]])  # XORs loaded byte with key
        byteWrite = bytes([rightRotate(byteXOR[0], rotation)])  # rotates XOR result
        print(key + str(rotation) + ": " + str(byteWrite))  # prints key, rotation and result
        index += 1  # increases index aka next letter

    index = 0  # while loop ended so resets index to 0

    while index != 26:  # for every letter in uppercase alphabet
        key = upper_alphabet[index]  # sets letter as key
        keyBytes = bytes(key, 'utf-8')  # formats the letter into a byte

        byteKey = keyBytes[0:1]  # idk pointless when checking single letter keys

        byteXOR = bytes([byteEnc[0] ^ byteKey[0]])  # XORs loaded byte with key
        byteWrite = bytes([rightRotate(byteXOR[0], rotation)])  # rotates XOR result
        print(key + str(rotation) + ": " + str(byteWrite))  # prints key, rotation and result
        index += 1  # increases index aka next letter
    index = 0  # while loop ended so resets index to 0
    rotation += 1  # increases rotation and repeats

file.close