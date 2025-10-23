//保护头文件，防止被间接多次引入，也可以使用现代的#pragma once
#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <cctype>

//使用枚举类，避免命名冲突
enum class Algorithm 
{
    CAESAR,
    XOR,
    REVERSE
};

class Crypto 
{
private:
    //用于储存当前当前加密算法
    Algorithm currentAlgorithm;

public:
    //构造函数，默认初始加密算法为凯撒加密
    Crypto(Algorithm algo = Algorithm::CAESAR);
    
    //设置加密算法
    void setAlgorithm(Algorithm algo);
    
    //文本加密和解密
    std::string encryptText(const std::string& text, const std::string& key);
    std::string decryptText(const std::string& encryptedText, const std::string& key);
    
    //文件加密和解密
    bool encryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key);
    bool decryptFile(const std::string& inputFile, const std::string& outputFile, const std::string& key);

private:
    //封装加密算法成员函数

    std::string caesarEncrypt(const std::string& text, int shift);
    std::string caesarDecrypt(const std::string& text, int shift);
    std::string xorEncryptDecrypt(const std::string& text, const std::string& key);
    std::string reverseEncrypt(const std::string& text);
    std::string reverseDecrypt(const std::string& text);
    int getShiftFromKey(const std::string& key);
};

#endif