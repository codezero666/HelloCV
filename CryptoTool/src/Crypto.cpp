#include "Crypto.h"
#include "FileHandler.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;

//初始化列表构造函数
Crypto::Crypto(Algorithm algo) : currentAlgorithm(algo) {}

//设置加密算法
void Crypto::setAlgorithm(Algorithm algo) 
{
    currentAlgorithm = algo;
}

//文本加密
string Crypto::encryptText(const string& text, const string& key) 
{
    switch (currentAlgorithm) 
    {
        case Algorithm::CAESAR:
            return caesarEncrypt(text, getShiftFromKey(key));
        case Algorithm::XOR:
            return xorEncryptDecrypt(text, key);
        case Algorithm::REVERSE:
            return reverseEncrypt(text);
        default:
            return caesarEncrypt(text, getShiftFromKey(key));
    }
}

//文本解密
string Crypto::decryptText(const string& encryptedText, const string& key) 
{
    switch (currentAlgorithm) 
    {
        case Algorithm::CAESAR:
            return caesarDecrypt(encryptedText, getShiftFromKey(key));
        case Algorithm::XOR:
            return xorEncryptDecrypt(encryptedText, key);
        case Algorithm::REVERSE:
            return reverseDecrypt(encryptedText);
        default:
            return caesarDecrypt(encryptedText, getShiftFromKey(key));
    }
}

//文件加密
bool Crypto::encryptFile(const string& inputFile, const string& outputFile, const string& key) 
{
    
    //读取文件内容
    string content = FileHandler::readFile(inputFile); 

    //加密后并写入文件
    string encrypted = encryptText(content, key);
    FileHandler::writeFile(outputFile,encrypted);
}

//文件解密
bool Crypto::decryptFile(const string& inputFile, const string& outputFile, const string& key) 
{
    //读取文件内容
    string content = FileHandler::readFile(inputFile); 
    
    //解密后并写入文件
    string decrypted = decryptText(content, key);
    FileHandler::writeFile(outputFile,decrypted);
}

//字符串密钥转换为ASCII，整型密钥当整型处理
int Crypto::getShiftFromKey(const string& key) 
{
    //默认key为3
    if (key.empty()) return 3;
    
    int shift = 0;
    if (key[0]<'0'||key[0]>'9')
    {
        for (char c : key) 
        {
            shift += static_cast<int>(c);
        }
    }
    else
    {
        shift = stoi(key);
    }
    return shift % 26;
}

//进行凯撒加密
string Crypto::caesarEncrypt(const string& text, int shift) 
{
    string result;
    
    for (char c : text) 
    {
        if (isalpha(c)) 
        {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        result += c;
    }
    
    return result;
}

//进行凯撒解密
string Crypto::caesarDecrypt(const string& text, int shift) 
{
    return caesarEncrypt(text, 26 - (shift % 26));
}

//进行XOR加密和解密
string Crypto::xorEncryptDecrypt(const string& text, const string& key) 
{
    //空密钥判断
    if (key.empty()) return text;
    
    string result;
    size_t keyLength = key.length(); //size_t为无符号整数
    
    for (size_t i = 0; i < text.length(); i++) 
    {
        result += text[i] ^ key[i % keyLength];
    }
    
    return result;
}

//进行反转加密
string Crypto::reverseEncrypt(const string& text) 
{
    string result = text;
    reverse(result.begin(), result.end());
    return result;
}

//进行反转解密
string Crypto::reverseDecrypt(const string& text) 
{
    return reverseEncrypt(text);
}