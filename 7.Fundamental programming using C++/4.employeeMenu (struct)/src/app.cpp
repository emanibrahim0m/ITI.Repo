#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

using namespace std;
#include <iostream>
#include "../include/utils.h"
#include "../include/employeesMenu.h"
#include "../include/employeesDB.h"
#include "../include/app.h"

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


// Track Key presses
void app()
{   
    // set menu x, y, color
    int x, y, colorCode;
    setMenuSetting(x, y, colorCode);
    
    // menu items
    const char* const menuItems[4] = {"Main Menu", "New Employee", "Display Employees", "Exit"};

    // draw menu + move curser to end of terminal
    int highlightedRow = 1;
    drawMainMenu(x, y, colorCode, menuItems, highlightedRow);
    cout << "\033[" << (y + 5) << ";1H" << flush;

    // employees list
    int employeeCount = 0;
    int newSize = EMPLOYEELISTSIZE;
    employeeStruct* employeeList = new employeeStruct[EMPLOYEELISTSIZE];

    while (true) {
        char key = getKeyPress();


        if (key == '\n' || key == '\r')
        {
            resetTerminal(x, y);

            if (highlightedRow == 1) {
                if (employeeCount < newSize)
                    pushEmployee(newSize, employeeCount, employeeList);
                else
                {
                    newSize*= 2;
                    employeeList = resizeList(employeeCount, employeeList, newSize);
                    pushEmployee(newSize, employeeCount, employeeList);
                }
                cout << "\n\nPress any key to return to menu...";
            }
            else if (highlightedRow == 2) {
                displayAllEmployees(employeeCount, employeeList);
                cout << "\n\nPress any key to return to menu...";
            }       
            else if (highlightedRow == 3) {
                delete[] employeeList;
                employeeList = nullptr;
                cout << endl << "Exiting ..." << endl;
                break; // Exit loop
            }

            cout << "\n\nPress any key to return to menu...";
            getKeyPress();
            
            resetTerminal(x, y);
            drawMainMenu(x, y, colorCode, menuItems, highlightedRow);
            cout << "\033[" << (y + 5) << ";1H" << flush;
        }

        #ifdef _WIN32
            // On Windows, arrow keys return 0 or -32 (0xE0) followed by a scan code
            if (key == 0 || key == -32) {
                char arrow = getKeyPress();
                
                switch (arrow) {

                    case 72: 
                    // Arrow Up
                        if (highlightedRow != 1)
                            highlightedRow--;

                    break;
                    
                    case 80: 
                    // Arrow Down
                        if (highlightedRow != MENUSIZE - 1)
                            highlightedRow++;
                    break;
                }
                
                drawMainMenu(x, y, colorCode, menuItems, highlightedRow);
                cout << "\033[" << (y + 5) << ";1H";
                continue;
            }
        #else

            // On Linux/macOS, arrow keys send an Escape sequence: '\x1b' '[' 'A'/'B'/'C'/'D'
            if (key == '\x1b') 
            {
                char seq1 = getKeyPress();
                if (seq1 == '[') 
                {
                    char seq2 = getKeyPress();
                    switch (seq2) 
                    {
                        
                        case 'A': 
                        // Arrow Up
                            if (highlightedRow != 1)
                                highlightedRow--;

                        ; break;

                        case 'B': 
                        // Arrow Down
                            if (highlightedRow != MENUSIZE - 1)
                                highlightedRow++;
                        ; break;
                    }

                    drawMainMenu(x, y, colorCode, menuItems, highlightedRow);
                    cout << "\033[" << (y + 5) << ";1H" << flush;
                    continue;
                }
                else
                    continue;
            }
        #endif
    }
}