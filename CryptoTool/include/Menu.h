//保护头文件，防止被间接多次引入，也可以使用现代的#pragma once
#ifndef MENU_H
#define MENU_H

#include "Crypto.h"
#include <string>

class Menu 
{
private:
    Crypto crypto;

public:
    void showMainMenu(); //展示菜单选项
    void handleChoice(int choice); //处理用户输入选项
    void textEncryptMenu(); //文本加密菜单
    void textDecryptMenu(); //文本解密菜单
    void fileEncryptMenu(); //文件加密菜单
    void fileDecryptMenu(); //文件解密菜单
    void selectAlgorithmMenu(); //选择加密算法菜单
    std::string getInput(const std::string& prompt); //获取输入
};

#endif