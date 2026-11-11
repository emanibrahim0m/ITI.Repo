#include <iostream>
#include "../include/employeesMenu.h"
#include "../include/employeesDb.h"

int getAxis();
int getColorCode();
void drawMainMenu(int x, int y, int initialMenuColor, const char* menuItems[]);

using namespace std;
#define DEFAULTCOLOR 30

int main() {

    // get x,y axis from user 
    int x, y;
    cout << "enter x axis: ";
    x = getAxis();
    cout << "enter y axis: ";
    y = getAxis();

    // get color code from user
    int colorCode;
    cout << "Select a color code:\n"
     << "  30: Black\n" << "  31: Red\n" << "  32: Green\n" << "  33: Yellow\n" 
     << "  34: Blue\n" << "  35: Magenta\n" << "  36: Cyan\n" << "  37: White\n"
     << "---------------------------------\n"
     << "Enter color code (30-37): ";
    colorCode = getColorCode();

    // reset terminal curser
    cout << "\033[2J\033[1;1H";
    
    // menu items
    const char* menuItems[4] = {"Main Menu", "New Employee", "Display Employees", "Exit"};

    // move, color menu item
    int initialMenuColor = colorCode;
    drawMainMenu(x, y, initialMenuColor, menuItems);

    cout << endl << endl;
    
    //
    int highlightedMenuItem = 0;

    cin.ignore(1000, '\n');
    while (true) {
        char key = getKeyPress();

        // display employeedb
        if (key == '\n' && highlightedMenuItem == 1) {
        }
        
        // add new employee to db
        if (key == '\n' && highlightedMenuItem == 2) {
        }

        // return to main menu
        if (key == '\n' && highlightedMenuItem == 0) {
            cout << "\033[2J";
            drawMainMenu(x, y, initialMenuColor, menuItems);
        }

        // exit
        if (key == '\n' && highlightedMenuItem == 3) {
            cout << "\033[2J";
            cout << "Exiting...\n";
            break;
        }

    #ifdef _WIN32
        // On Windows, arrow keys return 0 or -32 (0xE0) followed by a scan code
        if (key == 0 || key == -32) {
            char arrow = getKeyPress();
            switch (arrow) {
                case 72: 
                // Arrow Up
                    if (highlightedMenuItem != 0)
                    {
                        createMenuItem(x, y + highlightedMenuItem, DEFAULTCOLOR, menuItems[highlightedMenuItem]);
                        highlightedMenuItem--;
                        createMenuItem(x, y + highlightedMenuItem, colorCode, menuItems[highlightedMenuItem]);
                    }
                break;
                case 80: 
                // Arrow Down
                    if (highlightedMenuItem != 3)
                    {
                        createMenuItem(x, y + highlightedMenuItem, DEFAULTCOLOR, menuItems[highlightedMenuItem]);
                        highlightedMenuItem++;
                        createMenuItem(x, y + highlightedMenuItem, colorCode, menuItems[highlightedMenuItem]);
                    }
                break;
            }
            continue;
        }
    #else
        // On Linux/macOS, arrow keys send an Escape sequence: '\x1b' '[' 'A'/'B'/'C'/'D'
        if (key == '\x1b') {
            char seq1 = getKeyPress();
            if (seq1 == '[') {
                char seq2 = getKeyPress();
                switch (seq2) {
                    case 'A': 
                    // Arrow Up
                        if (highlightedMenuItem != 0)
                        {
                            createMenuItem(x, y + highlightedMenuItem, DEFAULTCOLOR, menuItems[highlightedMenuItem]);
                            highlightedMenuItem--;
                            createMenuItem(x, y + highlightedMenuItem, colorCode, menuItems[highlightedMenuItem]);
                        }
                        ; break;
                    case 'B': 
                    // Arrow Down
                        if (highlightedMenuItem != 3)
                        {
                            createMenuItem(x, y + highlightedMenuItem, DEFAULTCOLOR, menuItems[highlightedMenuItem]);
                            highlightedMenuItem++;
                            createMenuItem(x, y + highlightedMenuItem, colorCode, menuItems[highlightedMenuItem]);
                        }
                        ; break;
                }
                continue;
            }
        }
    #endif
    }

    return 0;   
}





// get x,y axis from user
int getAxis() {
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

void drawMainMenu(int x, int y, int initialMenuColor, const char* menuItems[])
{
    for (int i = 0; i < 4; i++)
    {
	    createMenuItem(x, y + i, initialMenuColor, menuItems[i]);
	    initialMenuColor = DEFAULTCOLOR;	
    }
}
