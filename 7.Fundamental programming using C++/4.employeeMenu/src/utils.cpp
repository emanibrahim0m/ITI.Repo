#include <iostream>

using namespace std;

// get Int from user
int getInt() {
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

