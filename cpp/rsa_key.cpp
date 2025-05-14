#include <iostream>
#include <string>
#include <gmpxx.h>

using namespace std;

// Convert string to mpz_class
mpz_class string_to_int(const string& str) {
    mpz_class result = 0;
    for (char c : str) {
        result *= 256;
        result += static_cast<unsigned char>(c);
    }
    return result;
}

// Convert mpz_class to string
string int_to_string(mpz_class number) {
    string result;
    while (number > 0) {
        mpz_class temp = number % 256;
        char c = temp.get_ui();
        result = c + result;
        number /= 256;
    }
    return result;
}

int main() {
    // Step 1: Choose primes p and q
    mpz_class p("130073");
    mpz_class q("150083");

    // Step 2: Compute n = p * q and phi(n)
    mpz_class n = p * q;
    mpz_class phi = (p - 1) * (q - 1);

    // Step 3: Choose public exponent e
    mpz_class e("65537");

    // Step 4: Compute private exponent d = e^(-1) mod phi
    mpz_class d;
    if (mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi.get_mpz_t()) == 0) {
        cerr << "Modular inverse does not exist!" << endl;
        return 1;
    }

    // Step 5: Input message
    string input;
    cout << "Enter a short message: ";
    getline(cin, input);

    // Convert input to integer
    mpz_class plaintext = string_to_int(input);

    if (plaintext >= n) {
        cerr << "Message too large for modulus!" << endl;
        return 1;
    }

    // Encrypt: c = m^e mod n
    mpz_class ciphertext;
    mpz_powm(ciphertext.get_mpz_t(), plaintext.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt: m = c^d mod n
    mpz_class decrypted;
    mpz_powm(decrypted.get_mpz_t(), ciphertext.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());

    // Convert decrypted number back to string
    string output = int_to_string(decrypted);
    cout << "Decrypted message: " << output << endl;

    return 0;
}

