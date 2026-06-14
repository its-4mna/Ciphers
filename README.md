# Ciphers

A collection of four fundamental cryptographic algorithms implemented in C++: Caesar Cipher, Diffie-Hellman Key Exchange, RSA, and XOR Cipher.

This project was developed as a collaborative assignment to explore classical and modern encryption techniques, key exchange protocols, and modular arithmetic.

## Implemented Algorithms

| Algorithm | Type | Key Length / Security |
|-----------|------|----------------------|
| Caesar Cipher | Symmetric, Substitution | Shift key (1–25) |
| Diffie-Hellman | Key Exchange Protocol | Relies on discrete logarithm problem |
| RSA | Asymmetric Encryption | Relies on integer factorization |
| XOR Cipher | Symmetric Stream Cipher | 8-bit key derived from shared secret |

## Tech Stack

- Language: C++
- Libraries: iostream, fstream, ctime, cctype
- Key Concepts: Modular arithmetic, prime number generation, file I/O, manual modulus operations (no % operator used throughout)

## Team & Contributions

This project was a collaborative effort by two team members, with each contributing equally.

**Aamna Mubasher (https://github.com/its-4mna) – Me**
- Implemented XOR Cipher: Integrated with Diffie-Hellman to generate a shared secret key, used as a stream cipher for encryption/decryption.
- Implemented RSA: Full implementation including prime generation, key pair generation, encryption, decryption, and file output.

**Alia Zainab (https://github.com/alia-git)**
- Implemented Caesar Cipher: Encryption/decryption with shift key, case preservation, file write/read operations.
- Implemented Diffie-Hellman: Key exchange protocol with prime modulus, generator, private/public key calculation, and shared secret generation.

## Getting Started

### Prerequisites
- A C++ compiler (g++, clang++, or MSVC)

### Compilation and Execution

Each algorithm is in a separate .cpp file. Compile and run any:

g++ caesar.cpp -o caesar
./caesar

Replace with: rsa.cpp, XOR.cpp, or Deffie-Hellman.cpp

## File Handling

All algorithms read from and write to files:
- RSA: Reads plaintext from user input; writes encrypted numbers to EncryptedText.txt, decrypted text to DecryptedText.txt
- Caesar Cipher: Writes results to ceasercipher.txt
- Diffie-Hellman: Writes all parameters and secrets to diffie_hellman.txt
- XOR Cipher: Writes encrypted output to xor_cipher.txt

## Purpose and Limitations

This project was created for educational purposes to demonstrate understanding of classical substitution ciphers (Caesar), symmetric stream ciphers (XOR), asymmetric encryption (RSA), and key exchange protocols (Diffie-Hellman).

Important Note: These implementations are not suitable for production use. They are designed for learning and may have vulnerabilities such as:
- Small prime sizes (RSA: primes selected from a small list of numbers up to 47)
- Manual modulus implementation without optimization
- No padding schemes (RSA is textbook implementation)
- Deterministic XOR key derived from Diffie-Hellman

## Acknowledgements

Thanks to our course instructor for guidance on cryptographic concepts, and to all team members for their dedicated contributions.
