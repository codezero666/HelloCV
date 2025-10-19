#include "Crypto.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <iostream>

using namespace std;

Crypto::Crypto(Algorithm algo) : currentAlgorithm(algo) {}

void Crypto::setAlgorithm(Algorithm algo) 
{
    currentAlgorithm = algo;
}

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

bool Crypto::encryptFile(const string& inputFile, const string& outputFile, const string& key) 
{
    ifstream inFile(inputFile);
    if (!inFile) 
    {
        return false;
    }
    
    string content((istreambuf_iterator<char>(inFile)), 
                   istreambuf_iterator<char>());
    inFile.close();
    
    string encrypted = encryptText(content, key);
    
    ofstream outFile(outputFile);
    if (!outFile) 
    {
        return false;
    }
    
    outFile << encrypted;
    outFile.close();
    
    return true;
}

bool Crypto::decryptFile(const string& inputFile, const string& outputFile, const string& key) 
{
    ifstream inFile(inputFile);
    if (!inFile) 
    {
        return false;
    }
    
    string content((istreambuf_iterator<char>(inFile)), 
                   istreambuf_iterator<char>());
    inFile.close();
    
    string decrypted = decryptText(content, key);
    
    ofstream outFile(outputFile);
    if (!outFile) 
    {
        return false;
    }
    
    outFile << decrypted;
    outFile.close();
    
    return true;
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