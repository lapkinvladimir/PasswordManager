//
// Created by User on 27.05.2023.
//

#ifndef PROJECTC_ENCRYPTION_H
#define PROJECTC_ENCRYPTION_H

#include <string>

class Encryption {
public:

    static std::string decryptLastLineFromFile(const std::string& filePath);
    static std::string encrypt(const std::string& plaintext);
    static std::string decrypt(const std::string& ciphertext, const std::string& key);
    static int calculateHash(const std::string& key);
    static std::string decryptText(const std::string& filePath, const std::string& decryptionKey);
    static std::string getFilePath();
    static std::string password;
};




#endif //PROJECTC_ENCRYPTION_H
