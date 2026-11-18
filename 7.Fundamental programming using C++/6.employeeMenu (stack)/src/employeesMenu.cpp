#include <iostream>
#include "../include/utils.h"
#include "../include/employeesMenu.h"

using namespace std;

// move curser to x,y axis
void moveCurser(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

// menu item color
void colorItem(int color)
{
    cout << "\033[" << color << "m";
}

// menu item text
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
    cout << "\033[0m";
}

// Print Full menu items 
void drawMainMenu(int x, int y, int colorCode, const char* const (&menuItems)[MENUSIZE], int highlightedRow)
{
    for (int i = 0; i < MENUSIZE; i++)
    {
        if (i == highlightedRow)
	        createMenuItem(x, y + i, colorCode, menuItems[i]);
	    else    
            createMenuItem(x, y + i, DEFAULTCOLOR, menuItems[i]);
    }
}