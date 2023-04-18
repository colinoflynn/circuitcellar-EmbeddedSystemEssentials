from Crypto.Cipher import AES

def chunks(l, n):
    return [l[i:i+n] for i in range(0, len(l), n)]

sram = open("sram_dump.bin", "rb").read()
ciphertext = open("fw_update_file.bin", "rb").read()

keys = chunks(sram, 16)

for offset,k in enumerate(keys):
    cipher = AES.new(bytearray(k), AES.MODE_ECB)
    dec = cipher.decrypt(bytearray(ciphertext))

    if b'System' in dec:
        print(offset*16)
        print(k)
        break