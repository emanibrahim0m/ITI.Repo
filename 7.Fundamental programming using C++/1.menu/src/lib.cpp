#include <iostream>
#include <string>
#include "../include/lib.h"

using namespace std;

// move menu to x,y axis
void moveItem(int x, int y, string& text)
{
    cout << "\033[" << y << ";" << x << "H" << text;
}

// color menu item
void colorItem(int color, int x, int y, string& text)
{
    cout << "\033[" << color << "m" << "\033[" << y << ";" << x << "H" << text << "\033[0m";
}
