#include "FileHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

string FileHandler::readFile(const string& filename) 
{
    ifstream file(filename);
    if (!file) 
    {
        throw runtime_error("无法打开文件: " + filename);
    }
    
    string content((istreambuf_iterator<char>(file)), 
                   istreambuf_iterator<char>());
    file.close();
    
    return content;
}

bool FileHandler::writeFile(const string& filename, const string& content) 
{
    ofstream file(filename);
    if (!file) 
    {
        return false;
    }
    
    file << content;
    file.close();
    
    return true;
}

bool FileHandler::fileExists(const string& filename) 
{
    ifstream file(filename);
    return file.good();
}