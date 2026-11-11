#ifndef MENU_H
#define MENU_H

#include <string>

//  prototypes
void moveItem(int x, int y);
void colorItem(int color);
void printItem(const std::string& text);
void createMenuItem(int x, int y, int color, const std::string& text);

#endif