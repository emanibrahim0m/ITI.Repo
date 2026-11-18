#ifndef UTILS_H
#define UTILS_H

#define DEFAULTCOLOR 30
#define MENUSIZE 4

int getInt();
int getColorCode();
void getText(char text[]);
void resetTerminal(int x, int y);
void setMenuSetting(int &x, int &y, int &colorCode);

#endif
