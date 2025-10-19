#include "FileHandler.h"
#include <fstream>
#include <iostream>

using namespace std;

//读取文件
string FileHandler::readFile(const string& filename) 
{
    ifstream file(filename);
    if (!file)
    {
        throw runtime_error("无法打开文件: " + filename);
    }
    
    //读取文件内全部内容
    string content((istreambuf_iterator<char>(file)), 
                   istreambuf_iterator<char>());
    file.close();
    
    return content;
}

//写入文件
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

//判断文件状态
bool FileHandler::fileExists(const string& filename) 
{
    ifstream file(filename);
    return file.good();
}