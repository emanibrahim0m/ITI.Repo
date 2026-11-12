#ifndef EMPLOYEESMENU_H
#define EMPLOYEESMENU_H

#include <string>

#define DEFAULTCOLOR 30


//  prototypes
void moveCurser(int x, int y);
void colorItem(int color);
void printItem(const std::string& text);
void createMenuItem(int x, int y, int color, const std::string& text);
void drawMainMenu(int x, int y, int initialMenuColor, const char* menuItems[], int highlightedMenuItem);

char getKeyPress();

#endif
