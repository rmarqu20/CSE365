
cypher = ("QVOEPQXKWZLAKWIFMLUIZDMTTQVOTQJMZQIVLIUAOIJJQMABNWZMEWZLAPWUMXIOMIZUILIAMMXAAISPIAZMIXXTQMARWKSABZIXAKWTTWKIBQWVALZIQVXQXMAKILMVKMAPWIZLMZXIZIUMBMZAACKKMAANCTTGNTMMBAJZQTTWATCVOMAPWZVQMABTQABMZQVMAVMA")
alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
key = 8
shift = 3
encrypt = ''
decrypt = ''

julia_file = open("juliaplaintext.txt.gz.enc", "rb")
print(julia_file)



# message = input('enter the message: ').upper()
message = "HELLO"
for i in message:
    position = alphabet.find(i)
    new_position = (position+key) % 26
    encrypt += alphabet[new_position]
# print(encrypt)


for i in cypher:
    pos = alphabet.find(i)
    new_pos = (pos-key) % 26
    decrypt += alphabet[new_pos]
print(cypher)
print(decrypt)
