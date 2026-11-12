#include <iostream>
#include <string>
#include "../include/employeesMenu.h"
#include "../include/employeesDb.h"
#include "../include/utils.h"

using namespace std;

int main() {

    // get x,y axis from user 
    int x, y;
    cout << "enter x axis: ";
    x = getInt();
    cout << "enter y axis: ";
    y = getInt();

    // get color code from user
    int colorCode;
    cout << "Select || 30: Black || 31: Red || 32: Green || 33: Yellow || 34: Blue || 35: Magenta || 36: Cyan || 37: White ||\n"
     << "Enter color code (30-37): ";
    colorCode = getColorCode();

    // reset terminal curser
    cout << "\033[2J\033[1;1H";

    // menu items 
    const char* menuItems[4] = {"Main Menu", "New Employee", "Display Employees", "Exit"};
    
    // move, color menu items first time 
    int highlightedMenuItem = 0;
    drawMainMenu(x, y, colorCode, menuItems, highlightedMenuItem);

    cout << endl << endl;
    
    // employee list & array of classes index
    employeeClass employeeList[EMPLOYEEARRAYSIZE];
    int classIndex = 0;

    cin.ignore(1000, '\n');
    while (true) {
        char key = getKeyPress();

        // add new employee to db
        if (key == '\n' && highlightedMenuItem == 1) {
            cout << "\033[2J";
            drawMainMenu(x, y, colorCode, menuItems, highlightedMenuItem);
            if (classIndex < EMPLOYEEARRAYSIZE)
            {
                // get employee info
                moveCurser(x, y + 6);
                string employeeName;
                cout << "EmployeeName: ";
                cin >> employeeName;
                cout << "EmployeeID: ";
                int id = getInt(); 
                cout << "EmployeeSalary: ";
                int salary = getInt(); 
                employeeList[classIndex].setEmployeeData(employeeName, id, salary);
                classIndex++;
                
                // clear window
                cout << "\033[2J";
                drawMainMenu(x, y, colorCode, menuItems, highlightedMenuItem);
                moveCurser(1, y + 6);
                cout << "Succesfully added new employee.";
                cin.ignore(1000, '\n');
            }
            else 
            {
                moveCurser(1, y + 6);
                cout << "No Space in Database." << flush;
            }
        }

        // display employeedb
        else if (key == '\n' && highlightedMenuItem == 2) 
        {
            cout << "\033[2J";
            drawMainMenu(x, y, colorCode, menuItems, highlightedMenuItem);
            moveCurser(1, y + 6);
            cout << "Employees List: " <<endl;
            if (classIndex == 0)
                cout << "No employee yet." << flush;
            for (int i = 0; i < classIndex; i++)
                employeeList[i].displayEmployeeData(i);
        }

        // return to main menu
        else if (key == '\n' && highlightedMenuItem == 0) {
            cout << "\033[2J";
            drawMainMenu(x, y  + highlightedMenuItem, colorCode, menuItems, highlightedMenuItem);
        }

        // exit
        else if (key == '\n' && highlightedMenuItem == 3) {
            cout << "\033[2J";
            cout << "Exiting...\n";
            return 0;
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
            else
                continue;
        }
    #endif
    }

    return 0;   
}






