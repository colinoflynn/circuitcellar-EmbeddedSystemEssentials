from Crypto.Cipher import AES

def chunks(l, n):
    return [l[i:i+n] for i in range(0, len(l), n)]

def word_reverse(k):
    return k[0:4][::-1] + k[4:8][::-1] + k[8:12][::-1] + k[12:16][::-1]

def byte_reverse(k):
    return k[::-1]

def test_result(ciphertext, k):
    cipher = AES.new(bytearray(k), AES.MODE_ECB)
    dec = cipher.decrypt(bytearray(ciphertext))
    if b"System" in dec:
        print(k)
        return True
    return False

sram = open("sram_dump.bin", "rb").read()
ct = open("fw_update_file.bin", "rb").read()
keys = chunks(sram, 16)

for offset,k in enumerate(keys):
    if test_result(ct, k):
        break
    if test_result(ct, byte_reverse(k)):
        break
    if test_result(ct, word_reverse(k)):
        break