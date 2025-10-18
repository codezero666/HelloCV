#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>

enum class Algorithm 
{
    CAESAR,
    XOR,
    REVERSE
};

class Crypto 
{
private:
    Algorithm currentAlgorithm;

public:
    Crypto(Algorithm algo = Algorithm::CAESAR);
    
    void setAlgorithm(Algorithm algo);
    
    std::string encryptText(const std::string& text, const std::string& key);
    std::string decryptText(const std::string& encryptedText, const std::string& key);
    
    bool encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key);
    bool decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key);

private:
    std::string caesarEncrypt(const std::string& text, int shift);
    std::string caesarDecrypt(const std::string& text, int shift);
    std::string xorEncryptDecrypt(const std::string& text, const std::string& key);
    std::string reverseEncrypt(const std::string& text);
    std::string reverseDecrypt(const std::string& text);
    int getShiftFromKey(const std::string& key);
};

#endif