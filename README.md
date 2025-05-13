# RSA Encryption & Decryption in Python

This is a simple implementation of RSA encryption and decryption in Python. The program demonstrates how public key encryption works using the RSA algorithm.

## Features
- **RSA Key Generation**: Generate RSA keys using two prime numbers.
- **Encryption**: Encrypt text using a public key.
- **Decryption**: Decrypt the encrypted text using a private key.
- **Input validation**: Ensure the plaintext is small enough to be encrypted with the given modulus.

## Prerequisites

Make sure to have **Python 3.x** installed on your system. You can download it from [python.org](https://www.python.org/downloads/).

### Required Libraries
- **sympy**: For prime number generation and modular arithmetic operations.

Install the required libraries using `pip`:

```bash
pip install sympy
