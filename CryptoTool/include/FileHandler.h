#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler 
{
public:
    static std::string readFile(const std::string& filename);
    static bool writeFile(const std::string& filename, const std::string& content);
    static bool fileExists(const std::string& filename);
};

#endif