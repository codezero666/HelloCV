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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        menu.handleChoice(choice);
        
    } while (choice != 0);
    
    return 0;
}