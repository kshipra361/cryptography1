import sympy as sp
e=65537  # Commonly used public exponent

def string_to_int(text):
    return int.from_bytes(text.encode('utf-8'), 'big')

def int_to_string(number):
    byte_length = (number.bit_length() + 7) // 8
    return number.to_bytes(byte_length, 'big').decode('utf-8', 'ignore')

def encrypt_decrypt(plaintext, e, n):
    ciphertext = pow(plaintext, e, n)
    decrypted_message = pow(ciphertext, d, n)  # Decryption
    print("ciphertext=", ciphertext)
    print("decrypted_message=", decrypted_message)
    decrypted_message= int_to_string(decrypted_message)
    print("decrypted_message=", decrypted_message)

## seleting two prime numbers
p=sp.prime(10**10)
q=sp.prime(15 * 10**10)
n=p*q
d=sp.mod_inverse(e, (p-1)*(q-1))  # Calculate d using the modular inverse
# Repeatedly take input until valid
while True:
    text = input("Enter the text to be encrypted: ")
    plaintext = string_to_int(text)
    if plaintext < n:
        print("plaintext=", plaintext)
        encrypt_decrypt(plaintext, e, n)
        break
    else:
        print("\nThe plaintext is too large for the given modulus.")
        print("Please enter a smaller text.")
        print("Max size of the text:", n.bit_length() // 8, "bytes")
        print("Approx max characters allowed:", (n.bit_length() // 8) // 2, "characters\n")