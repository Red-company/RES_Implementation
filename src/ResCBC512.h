/**
 * @file    ResCBC512.h
 * @brief   Definition of Res CBC 512 bits algorithm.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_RESCBC512_H
#define RED_RESCBC512_H

#include <string>

namespace Red {
    /**
     * @brief EncryptResCBC512
     *
     * @param in    String to encrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Encrypted string
     */
    std::string * EncryptResCBC512(
                              const std::string& in,
                              const std::string_view key,
                              const std::string_view iv
                             );

    /**
     * @brief DecryptResCBC512
     *
     * @param in    String to decrypt
     * @param key   Private key
     * @param iv    Initialization vector
     *
     * @return Decrypted string
     */
    std::string * DecryptResCBC512(
                              const std::string& in,
                              const std::string_view key,
                              const std::string_view iv
                             );
}

#endif // RED_RESCBC512_H
