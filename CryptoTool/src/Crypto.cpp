#include "Crypto.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>

using namespace std;

Crypto::Crypto(Algorithm algo) : currentAlgorithm(algo) {}

void Crypto::setAlgorithm(Algorithm algo) 
{
    currentAlgorithm = algo;
}

string Crypto::encryptText(const string& text, const string& key) 
{
    switch (currentAlgorithm) {
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
    switch (currentAlgorithm) {
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
    if (!inFile) {
        return false;
    }
    
    string content((istreambuf_iterator<char>(inFile)), 
                   istreambuf_iterator<char>());
    inFile.close();
    
    string encrypted = encryptText(content, key);
    
    ofstream outFile(outputFile);
    if (!outFile) {
        return false;
    }
    
    outFile << encrypted;
    outFile.close();
    
    return true;
}

bool Crypto::decryptFile(const string& inputFile, const string& outputFile, const string& key) 
{
    ifstream inFile(inputFile);
    if (!inFile) {
        return false;
    }
    
    string content((istreambuf_iterator<char>(inFile)), 
                   istreambuf_iterator<char>());
    inFile.close();
    
    string decrypted = decryptText(content, key);
    
    ofstream outFile(outputFile);
    if (!outFile) {
        return false;
    }
    
    outFile << decrypted;
    outFile.close();
    
    return true;
}

string Crypto::caesarEncrypt(const string& text, int shift) 
{
    string result;
    
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
        result += c;
    }
    
    return result;
}

string Crypto::caesarDecrypt(const string& text, int shift) 
{
    return caesarEncrypt(text, 26 - (shift % 26));
}

string Crypto::xorEncryptDecrypt(const string& text, const string& key) {
    if (key.empty()) return text;
    
    string result;
    size_t keyLength = key.length();
    
    for (size_t i = 0; i < text.length(); ++i) {
        result += text[i] ^ key[i % keyLength];
    }
    
    return result;
}

string Crypto::reverseEncrypt(const string& text) 
{
    string result = text;
    reverse(result.begin(), result.end());
    return result;
}

string Crypto::reverseDecrypt(const string& text) 
{
    return reverseEncrypt(text);
}

int Crypto::getShiftFromKey(const string& key) 
{
    if (key.empty()) return 3;
    
    int shift = 0;
    for (char c : key) {
        shift += static_cast<int>(c);
    }
    return shift % 26;
}