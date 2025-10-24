#include <limits>
#include <iostream>
#include "Menu.h"

using namespace std;

int main() 
{
    Menu menu;
    int choice;
    
    do {
        menu.showMainMenu();
        cin >> choice;
        //清除之前的输入，减少内存占用
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        //处理输入的选项
        menu.handleChoice(choice);
        
    } while (choice != 0); //按0退出
    
    return 0;
}