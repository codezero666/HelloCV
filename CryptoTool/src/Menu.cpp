#include "Menu.h"
#include "FileHandler.h"
#include <iostream>
#include <limits>

using namespace std;

//展示终端操作菜单
void Menu::showMainMenu() 
{
    cout << "\n=== 简易文本加密解密工具 ===\n";
    cout << "1. 文本加密\n";
    cout << "2. 文本解密\n";
    cout << "3. 文件加密\n";
    cout << "4. 文件解密\n";
    cout << "5. 选择加密算法\n";
    cout << "0. 退出\n";
    cout << "请选择功能: ";
}

//处理输入的选项
void Menu::handleChoice(int choice) 
{
    switch (choice) 
    {
        case 1:
            textEncryptMenu();
            break;
        case 2:
            textDecryptMenu();
            break;
        case 3:
            fileEncryptMenu();
            break;
        case 4:
            fileDecryptMenu();
            break;
        case 5:
            selectAlgorithmMenu();
            break;
        case 0:
            cout << "感谢使用，ヾ(￣▽￣)Bye~Bye~\n";
            break;
        default:
            cout << "无效选择，请重新输入！\n";
    }
}


//给出提示信息并获取输入
string Menu::getInput(const string& prompt) 
{
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

//文本加密菜单
void Menu::textEncryptMenu() 
{
    cout << "\n--- 文本加密 ---\n";
    string text = getInput("请输入要加密的文本: ");
    string key = getInput("请输入密钥: ");
    
    string encrypted = crypto.encryptText(text, key);
    cout << "加密结果: " << encrypted << endl;
}

//文本解密菜单
void Menu::textDecryptMenu() 
{
    cout << "\n--- 文本解密 ---\n";
    string text = getInput("请输入要解密的文本: ");
    string key = getInput("请输入密钥: ");
    
    string decrypted = crypto.decryptText(text, key);
    cout << "解密结果: " << decrypted << endl;
}

//文件加密菜单
void Menu::fileEncryptMenu() 
{
    cout << "\n--- 文件加密 ---\n";
    string inputFile = getInput("请输入要加密的文件路径: ");
    
    if (!FileHandler::fileExists(inputFile)) 
    {
        cout << "文件不存在！\n";
        return;
    }
    
    string key = getInput("请输入密钥: ");
    string outputFile = getInput("请输入输出文件路径: ");
    
    if (crypto.encryptFile(inputFile, outputFile, key)) 
    {
        cout << "加密结果已保存到: " << outputFile << endl;
    } else {
        cout << "文件加密失败！\n";
    }
}

//文件解密菜单
void Menu::fileDecryptMenu() 
{
    cout << "\n--- 文件解密 ---\n";
    string inputFile = getInput("请输入要解密的文件路径: ");
    
    if (!FileHandler::fileExists(inputFile)) 
    {
        cout << "文件不存在！\n";
        return;
    }
    
    string key = getInput("请输入密钥: ");
    string outputFile = getInput("请输入输出文件路径: ");
    
    if (crypto.decryptFile(inputFile, outputFile, key)) 
    {
        cout << "解密结果已保存到: " << outputFile << endl;
    } else {
        cout << "文件解密失败！\n";
    }
}

//选择加密算法菜单
void Menu::selectAlgorithmMenu() 
{
    cout << "\n--- 选择加密算法 ---\n";
    cout << "1. 凯撒密码 (Caesar Cipher)\n";
    cout << "2. XOR加密\n";
    cout << "3. 反转加密\n";
    cout << "请选择算法: ";
    
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) 
    {
        case 1:
            crypto.setAlgorithm(Algorithm::CAESAR);
            cout << "已选择凯撒密码算法\n";
            break;
        case 2:
            crypto.setAlgorithm(Algorithm::XOR);
            cout << "已选择XOR加密算法\n";
            break;
        case 3:
            crypto.setAlgorithm(Algorithm::REVERSE);
            cout << "已选择反转加密算法\n";
            break;
        default:
            cout << "无效选择，保持当前算法\n";
    }
}