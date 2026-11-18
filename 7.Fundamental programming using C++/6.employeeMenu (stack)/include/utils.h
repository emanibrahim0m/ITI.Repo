#ifndef UTILS_H
#define UTILS_H

#define DEFAULTCOLOR 30
#define MENUSIZE 5

int getInt();
int getColorCode();
void setMenuSetting(int &x, int &y, int &colorCode);
void getText(char text[]);
void resetTerminal(int x, int y);

#endif
