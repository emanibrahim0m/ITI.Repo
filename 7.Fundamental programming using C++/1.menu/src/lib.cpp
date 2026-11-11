#include <iostream>
#include <string>
#include "../include/lib.h"

using namespace std;

// move curser to x,y axis
void moveCurser(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

// color menu item
void colorItem(int color)
{
    cout << "\033[" << color << "m";
}

// print menu item
void printItem(const string& text)
{
    cout << text;
}

// Print menu item
void createMenuItem(int x, int y, int color, const string& text)
{
    moveCurser(x, y);
    colorItem(color);
    printItem(text);
}