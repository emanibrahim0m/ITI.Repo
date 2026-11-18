#include <iostream>
#include "../include/utils.h"

using namespace std;

// get x,y axis from user
int getInt() {
    int n;
    while (!(cin >> n) || n < 0 || n > 20)
    {
        cin.clear(); 
        cin.ignore(100, '\n');
        cout << "Invalid input. Enter a number: "; 
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
    cout << "Select || 30: Black || 31: Red || 32: Green || 33: Yellow || 34: Blue || 35: Magenta || 36: Cyan || 37: White ||\n"
     << "Enter color code (30-37): ";
    while (!(cin >> n) || n < 30 || n > 37)
    {
        cin.clear();
        cin.ignore(100, '\n');
    }
    cin.ignore(1000, '\n');
    return n;
}

// get text from user
void getText(char text[])
{
    cin.getline(text, 50);
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input too long! Please keep it under 50 characters.\n";
    }
}

// reset terminal
void resetTerminal(int x, int y)
{
    cout << "\033[2J\033[" << y << ";" << x << "H" << flush;
}

// 
void setMenuSetting(int &x, int &y, int &colorCode)
{
    // get x,y axis from user 
    cout << "enter x axis: ";
    x = getInt();
    cout << "enter y axis: ";
    y = getInt();
    
    // get color code from user
    colorCode = getColorCode();
    
    // reset terminal curser
    resetTerminal(x, y);
}

