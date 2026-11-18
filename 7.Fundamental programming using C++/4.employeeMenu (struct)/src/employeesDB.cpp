#include <iostream>
#include "../include/employeesMenu.h"
#include "../include/employeesDB.h"

using namespace std;

// get Employee id 
int getEmployeeID(int employeeCount, const employeeStruct employeeList[]) {
    int n;
    bool isDuplicate;
    
    do {
        isDuplicate = false;

        // check if valid id
        while (!(cin >> n) || n < 0) 
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid ID. Enter ID: ";
        }

        // Check if dublicate id
        for (int i = 0; i < employeeCount; i++) 
        {
            if (n == employeeList[i].id) 
            {
                isDuplicate = true;
                cout << "ID already exists. Enter another ID: ";
                break;
            }
        }

    } while (isDuplicate);
    cin.ignore(10000, '\n');
    return n;
}

// get employee salary
int getSalary() {
    int n;
    // check if valid
    while (!(cin >> n) || n < 0 || n > 8000)
    {
        cin.clear(); 
        cin.ignore(100, '\n');
        cout << "Invalid salary. Enter Salary: "; 
    }
    cin.ignore(10000, '\n');
    return n;
}

// new employee
void pushEmployee(int listSize, int& employeeCount, employeeStruct employeeList[])
{
    if (employeeCount >= listSize) {
        cout << "Employee list is full!\n";
        return;
    }

    cout << "EmployeeName: ";
    cin >> employeeList[employeeCount].name;

    cin.ignore(10000, '\n');

    cout << "EmployeeID: ";
    employeeList[employeeCount].id = getEmployeeID(employeeCount, employeeList);    

    cout << "EmployeeSalary: ";
    employeeList[employeeCount].salary = getSalary();

    cout << "Successfully added new employee";
    employeeCount++;
}

// resize array 
employeeStruct* resizeList(const int& employeeCount, employeeStruct employeeList[], int newsize)
{
    employeeStruct* newemployeeList = new employeeStruct[newsize];
    for (int i = 0; i < employeeCount; i++)
    {
        newemployeeList[i] = employeeList[i];
    }
    delete[] employeeList; 
    return newemployeeList;
}

// display all employee
void displayAllEmployees(int employeeCount, const employeeStruct employeeList[])
{
    if (employeeCount == 0) {
        cout << "No employees found.\n";
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        employeeList[i].displayEmployeeData(i + 1);
    }
}

