# RES_Implementation

## What is it and what does it do?

This is a small and portable C++ implementation of the Red Encryption Standart(RES).
RES is based on Advanced Encryption Standart(AES). 
Is part of RedLibrary.

## What does RES consist of?
RES includes 2 encryption modes: [ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_.28ECB.29) and [CBC](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Cipher_Block_Chaining_.28CBC.29) with 3 key length algorithms for each of them:

* ECB
  * ResECB 512 bits key
  * ResECB 1024 bits key
  * ResECB 1536 bits key
  
* CBC
  * ResCBC 512 bits key
  * ResCBC 1024 bits key
  * ResCBC 1536 bits key

## How to use it?

There are 6 files for each of algorithms.

```C
// ResECB512
const std::string EncryptResECB512(const std::string& in, const std::string_view key);
const std::string DecryptResECB512(const std::string& in, const std::string_view key);

// ResECB1024
const std::string EncryptResECB1024(const std::string& in, const std::string_view key);
const std::string DecryptResECB1024(const std::string& in, const std::string_view key);

// ResECB1536
const std::string EncryptResECB1536(const std::string& in, const std::string_view key);
const std::string DecryptResECB1536(const std::string& in, const std::string_view key);

// ResCBC512
const std::string EncryptResCBC512(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptResCBC512(const std::string& in, const std::string_view key, const std::string_view iv);

// ResCBC1024
const std::string EncryptResCBC1024(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptResCBC1024(const std::string& in, const std::string_view key, const std::string_view iv);

// ResCBC1536
const std::string EncryptResCBC1536(const std::string& in, const std::string_view key, const std::string_view iv);
const std::string DecryptResCBC1536(const std::string& in, const std::string_view key, const std::string_view iv);
```

**Tech notes:**
 * Padding is provided for "in" params. "Iv" should equals 16 bytes.
 * ECB mode is considered unsafe for most uses and is not implemented in streaming mode. See [wikipedia's article on ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_(ECB)) for more details.
 * This library is designed for small code size and simplicity, intended for cases where small binary size, low memory footprint and portability is more important than high performance.

**Notes:**
 * If you want to route result of encryption to `std::cout`, you should convert string to hexadecimal system, in other way you will get strange output!
 * There is no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

Do contact me if you have improvements to the code(contacts is in each of source files). 

All material in this repository is in the public domain.
