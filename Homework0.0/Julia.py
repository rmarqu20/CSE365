
with open("juliaplaintext.txt.gz.enc", "rb") as f:
    data = f.read()

# print(data)
# for ch in data:
#     print(bin((ch)))

xor_key = "VfUpWlNDygsH"
xor_binary = ' '.join(format(ord(i), 'b') for i in xor_key)
print(xor_binary)

encrypted_message = data
message = ''

for i in encrypted_message:
    val = data[i]
    character = chr(ord('A') + (val - ord('A')) % 26)
    message = message + character

print(message)
encrypted_message_binary = ' '.join(format(ord(i), 'b') for i in message)
print(encrypted_message_binary)
