#ifndef EMPLOYEESMENU_H
#define EMPLOYEESMENU_H

#include <string>

//  prototypes
void moveCurser(int x, int y);
void colorItem(int color);
void printItem(const std::string& text);
void createMenuItem(int x, int y, int color, const std::string& text);

char getKeyPress();

#endif
