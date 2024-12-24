# RSA Encryption Program

This program demonstrates a basic implementation of RSA encryption and decryption using the Boost Multiprecision library for handling large integers. It includes both the main logic and the supporting library functions.

There are two files:

1) rsa.cpp
Contains the main program logic:
- Defines values for the RSA algorithm (‘p’, ‘q’, ‘e’, etc.).
- Reads a plaintext message.
- Encrypts the message using the public key.
- Decrypts the message using the private key.

2) rsa_library.h
A header file that provides the following utility functions:

- **BlockToInt**: Converts a block of characters into a large integer.
- **IntToBlock**: Converts a large integer back into a block of characters.
- **calculateBlockSize**: Determines the optimal block size based on the modulus ‘n’.
- **encryptMessage**: Encrypts a string message into a vector of encrypted blocks using the public key.
- **decryptMessage**: Decrypts a vector of encrypted blocks back into the original string using the private key.

How It Works
1. The program defines the prime numbers `p` and `q`.
2. Calculates the modulus `n` and Euler's totient `phi`.
3. Computes the private key ‘d’ using a simple iterative approach.
4. The user-defined message is encrypted using the public key `(e, n)`.
5. The encrypted message is decrypted using the private key `(d, n)`.


 Steps to compile:
 1) Clone the repository or copy the files.
 2) Create a CMakeLists.txt file for easier compilation (the example is added in this repository ( CMakeLists.txt file))
 

Dependencies
- Boost Multiprecision Library: Required for handling large integers.

Example Output

Original message: What I've done I'll face myself To cross out what I've become Erase myself And let go of what I've done

Encrypted message: 1029384756 9876543210 1234567890 ...

Decrypted message: What I've done I'll face myself To cross out what I've become Erase myself And let go of what I've done


Acknowledgements
- Boost Multiprecision Library for enabling operations with large integers.
