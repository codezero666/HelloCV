//保护头文件，防止被间接多次引入，也可以使用现代的#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler 
{
public:
    //使用静态，可以直接通过类名调用，不需要创建对应对象

    static std::string readFile(const std::string& filename); //读取文件
    static bool writeFile(const std::string& filename, const std::string& content); //写入文件
    static bool fileExists(const std::string& filename); //判断文件状态
};

#endif