#include <iostream>
#include <string>
#include "../include/lib.h"

int getAxis();
int getColorCode();

using namespace std;
#define DEFAULTCOLOR 30

int main() {
    // get x,y axis from user 
    int x, y;

    cout << "enter x axis: ";
    x = getAxis();

    cout << "enter y axis: ";
    y = getAxis();

    // get color code from user
    int colorCode;
    cout << "Select a color code:\n"
     << "  30: Black\n" << "  31: Red\n" << "  32: Green\n" << "  33: Yellow\n" 
     << "  34: Blue\n" << "  35: Magenta\n" << "  36: Cyan\n" << "  37: White\n"
     << "---------------------------------\n"
     << "Enter color code (30-37): ";
    colorCode = getColorCode();
    // int defaultColor = 30;

    // reset terminal curser
    cout << "\033[2J\033[1;1H";
    
    // menu items
    string menuOne = "Main Menu";
    string menuTwo = "New Employee";
    string menuThree = "Display Employees";
    string menuFour = "Exit";

    // move, color menu item
    createMenuItem(x, y, colorCode, menuOne);
    createMenuItem(x, y + 1, DEFAULTCOLOR, menuTwo);
    createMenuItem(x, y + 2, DEFAULTCOLOR, menuThree);
    createMenuItem(x, y + 3, DEFAULTCOLOR, menuFour);

    // return curser to end of terminal
    cout << "\033[" << (y + 5) << ";1H";

    return 0;   
}


// get x,y axis from user
int getAxis() {
    int n;
    
    while (!(cin >> n) || n < 0)
    {
        cin.clear(); 
        cin.ignore(100, '\n');
        cout << "Not a valid number try again: ";
    }
    return n;
    /*
    if (cin.fail() || n < 0)
    {
        cout << "Not a valid number.";
    }
    */
}

// get color code from user
int getColorCode() {
    int n;
    while (!(cin >> n) || n < 30 || n > 37)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "enter color code From 30-37: ";
    }
    return n;
}