//保护头文件
#ifndef MENU_H
#define MENU_H

#include "Crypto.h"
#include <string>

class Menu 
{
private:
    Crypto crypto;

public:
    void showMainMenu();
    void handleChoice(int choice);
    void textEncryptMenu();
    void textDecryptMenu();
    void fileEncryptMenu();
    void fileDecryptMenu();
    void selectAlgorithmMenu();
    std::string getInput(const std::string& prompt);
};

#endif