#include <iostream>
#include <string>
#include "../include/employeesMenu.h"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

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
    cout << text << flush;
}

// Print menu item
void createMenuItem(int x, int y, int color, const string& text)
{
    moveCurser(x, y);
    colorItem(color);
    printItem(text);
}

// Print Full menu items
void drawMainMenu(int x, int y, int colorCode, const char* menuItems[], int highlightedMenuItem)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == highlightedMenuItem)
	        createMenuItem(x, y + i, colorCode, menuItems[i]);
	    else    
            createMenuItem(x, y + i, DEFAULTCOLOR, menuItems[i]);
    }
}





// track user key presses
char getKeyPress() {
#ifdef _WIN32
    // _getch() reads a single character without echoing or waiting for Enter
    return static_cast<char>(_getch());
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);           // Save current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // Disable line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply new settings immediately

    char ch = 0;
    if (read(STDIN_FILENO, &ch, 1) < 0) {
        ch = 0;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore original settings
    return ch;
#endif
}