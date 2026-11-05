#include <iostream>
#include <string>
#include "../include/lib.h"

int getAxis();
int getColorCode();

using namespace std;

int main() {
    // get x,y axis from user 
    int x, y;

    cout << "enter x axis: ";
    x = getAxis();
    cin >> x;

    cout << "enter y axis: ";
    y = getAxis();
    cin >> y;

    // get color code from user
    int colorCode;
    cout << "Select a color code:\n"
     << "  30: Black\n" << "  31: Red\n" << "  32: Green\n" << "  33: Yellow\n" 
     << "  34: Blue\n" << "  35: Magenta\n" << "  36: Cyan\n" << "  37: White\n"
     << "---------------------------------\n"
     << "Enter color code (30-37): ";
    colorCode = getColorCode();

    // reset terminal curser
    cout << "\033[2J\033[1;1H";
    
    // menu items
    string menuOne = "Main Menu";
    string menuTwo = "New Screen";
    string menuThree = "Display Screen";
    string menuFour = "Exit";

    // move menu
    // color menu item
    colorItem(colorCode, x, y, menuOne);
    moveItem(x, y + 1, menuTwo);
    moveItem(x, y + 2, menuThree);
    moveItem(x, y + 3, menuFour);

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
        // cin.ignore(HowManyToIgnore, StopWhenYouSeeThis);
        cin.ignore(100, '\n');
        cout << "Not a valid number try again: ";
    }
    return n;
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