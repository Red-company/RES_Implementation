# RES_Implementation

## What is it?

This is a small and portable C++ implementation of the Red Encryption Standart(RES).
RES is upgraded version of Advanced Encryption Standart(AES) and is a part of RedLibrary(Now developing).

## Where to use?

RES has excess level of encryption, and should be used in specific tasks, where you need absolute encryption and ready to sacrifice your perfomance. If you need perfomance, I advise you to use AES([Here's my implementation](https://github.com/vladimirrogozin/AES_Implementation)).

## What does RES consist of?
RES includes 2 encryption modes: [ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_.28ECB.29) and [CBC](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Cipher_Block_Chaining_.28CBC.29) with 3 key length cases for each of them:

* ECB
  * ResECB 512 bits key
  * ResECB 1024 bits key
  * ResECB 1536 bits key
  
* CBC
  * ResCBC 512 bits key
  * ResCBC 1024 bits key
  * ResCBC 1536 bits key

## How to use it?

There are 7 header files(6 with algorithms and 1 with shared definitions) and 6 source files(for each of algorithm).

```C
// ResECB512.h
const std::string EncryptResECB512(const std::string& in, const std::string_view key);
const std::string DecryptResECB512(const std::string& in, const std::string_view key);

// ResECB1024.h
const std::string EncryptResECB1024(const std::string& in, const std::string_view key);
const std::string DecryptResECB1024(const std::string& in, const std::string_view key);

// ResECB1536.h
const std::string EncryptResECB1536(const std::string& in, const std::string_view key);
const std::string DecryptResECB1536(const std::string& in, const std::string_view key);

// ResCBC512.h
const std::string EncryptResCBC512(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptResCBC512(const std::string& in, const std::string_view key, const std::string_view iv);

// ResCBC1024.h
const std::string EncryptResCBC1024(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptResCBC1024(const std::string& in, const std::string_view key, const std::string_view iv);

// ResCBC1536.h
const std::string EncryptResCBC1536(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptResCBC1536(const std::string& in, const std::string_view key, const std::string_view iv);
```

**Tech notes:**
 * Padding is provided only for "in" params. "Iv" should equals 16 bytes. Key length(in bytes) is calculated using the formula: `KEY_LENGTH / 8`.
 * ECB mode is considered unsafe for most uses and is not implemented in streaming mode. See [wikipedia's article on ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_(ECB)) for more details.
 * This library is designed for small code size and simplicity, intended for cases where small binary size, low memory footprint and portability is more important than high performance.

**Notes:**
 * If you want to route result of encryption to `std::cout`, you should convert string to hexadecimal system, in other way you will get bad output!
  * **Convertion functions are included in each of examples.**
 * There is no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

Do contact me if you have improvements to the code(contacts are in each of source files). 

All material in this repository is in the public domain.
