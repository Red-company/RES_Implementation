#include <iostream>

#include "ResCBC512.h"

int main() {
    // Key length is 64.
    std::string key = "0123456789abcdef12345678123456780123456789abcdef1234567812345678";
    std::string in  = "0123456789abcdef";
    std::string iv  = "0123456789abcdef";

    std::string EncryptedStr = Red::EncryptResCBC512(in, key, iv);
    std::string EncryptedHex = GetHexArray(EncryptedStr);

    std::cout << "Encrypted(hex): '" << EncryptedHex << "'." << std::endl;

    std::string ForDecrypt = GetStrArray(EncryptedHex);
    std::string Decrypted  = Red::DecryptResCBC512(ForDecrypt, key, iv);

    std::cout << "Decrypted(str): '" << Decrypted << "'." << std::endl;

    return 0;
}
