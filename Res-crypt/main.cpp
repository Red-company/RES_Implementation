#include <iostream>
#include <string>

#include "Res/ResCBC512.h"
#include "Res/ResCBC1024.h"
#include "Res/ResCBC1536.h"
#include "Res/ResECB512.h"
#include "Res/ResECB1024.h"
#include "Res/ResECB1536.h"
#include "Hex.h"

int main() {
    // Variables.
    std::string inp;

    std::string operation;
    std::string mode;

    std::string key;
    std::string iv;
    std::string msg;

    while (true) {

        // Operations.
        while (true) {
            system("clear");
            std::cout << "\033[4mChoose operation:\033[0m 1)Encode 2)Decode.";

            std::cout << std::endl << std::endl << "[\033[91mRes\033[0m]  > ";

            inp.clear();
            key.clear();
            iv.clear();
            msg.clear();

            std::cin >> inp;

            // Operation selection.
            if (inp == "1" || inp == "2") {
                if (inp == "1") {
                    operation = "Encode";

                } else if (inp == "2") {
                    operation = "Decode";
                }

                break;
            }
        }

        // Mode selection.
        while (true) {
            system("clear");
            std::cout << "\033[4mChoose mode:\033[0m 1)CBC-512. 2)CBC-1024. 3)CBC-1536. 4)ECB-512. 5)ECB-1024. 6)ECB-1536.";
            std::cout << std::endl << std::endl << "[\033[91mRes\033[0m]  > ";

            std::cin >> inp;

            if (inp == "1" || inp == "2" || inp == "3" || inp == "4" || inp == "5" || inp == "6") {
                if (inp == "1") {
                    mode = "CBC-512";

                } else if (inp == "2") {
                    mode = "CBC-1024";

                } else if (inp == "3") {
                    mode = "CBC-1536";

                } else if (inp == "4") {
                    mode = "ECB-512";

                } else if (inp == "5") {
                    mode = "ECB-1024";

                } else if (inp == "6") {
                    mode = "ECB-1536";
                }

                break;
            }
        }

        // Entering key.
        {
            system("clear");
            std::cout << "\033[4mEnter a key.\033[0m" << std::endl << "[\033[91mRes\033[0m/\033[94m" + mode + "\033[0m] > ";

            std::cin.ignore();
            inp.clear();
            getline(std::cin, key);
            std::cout << std::endl << std::endl;
        }

        // Entering iv.
        if (mode == "CBC-512" || mode == "CBC-1024" || mode == "CBC-1536") {
            std::cout << "\033[4mEnter an initialization vector.\033[0m" << std::endl << "[\033[91mRes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, iv);
            std::cout << std::endl << std::endl;
        }

        // Encrypting.
        if (operation == "Encode") {
            std::cout << "\033[4mEnter a message(str).\033[0m" << std::endl << "[\033[91mRes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;

            std::cout << "[\033[91mRes\033[0m/\033[94m" + mode + "\033[0m] \033[4mEncrypted message(hex):\033[0m";

            if (mode == "CBC-512") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptResCBC512(msg, key, iv));

            } else if (mode == "CBC-1024") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptResCBC1024(msg, key, iv));

            } else if (mode == "CBC-1536") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptResCBC1536(msg, key, iv));

            } else if (mode == "ECB-512") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptResECB512(msg, key));

            } else if (mode == "ECB-1024") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptResECB1024(msg, key));

            } else if (mode == "ECB-1536") {
                std::cout << std::endl << std::endl << Red::GetHexArray(Red::EncryptResECB1536(msg, key));
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();

        } else if (operation == "Decode") {
            std::cout << "\033[4mEnter a message(hex).\033[0m" << std::endl << "[\033[91mRes\033[0m/\033[94m" + mode + "\033[0m] > ";

            inp.clear();
            getline(std::cin, msg);
            std::cout << std::endl << std::endl;
            std::cout << msg.length() << ":" << msg << std::endl;

            std::cout << "[\033[91mRes\033[0m/\033[94m" + mode + "\033[0m] \033[4mDecrypted message(str):\033[0m";
            std::cout << std::endl << std::endl;

            if (mode == "CBC-512") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptResCBC512(Red::GetStrArray(msg), key, iv);

            } else if (mode == "CBC-1024") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptResCBC1024(Red::GetStrArray(msg), key, iv);

            } else if (mode == "CBC-1536") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptResCBC1536(Red::GetStrArray(msg), key, iv);

            } else if (mode == "ECB-512") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptResECB512(Red::GetStrArray(msg), key);

            } else if (mode == "ECB-1024") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptResECB1024(Red::GetStrArray(msg), key);

            } else if (mode == "ECB-1536") {
                std::string a = Red::GetStrArray(msg.c_str());
                std::cout << Red::DecryptResECB1536(Red::GetStrArray(msg), key);
            }

            std::cout << std::endl << std::endl << std::endl << "Press Enter to continue.";

            std::cin.get();
        }
    }
}
