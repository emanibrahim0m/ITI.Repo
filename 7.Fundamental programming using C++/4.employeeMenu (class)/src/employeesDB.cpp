#include <iostream>
#include "../include/employeesMenu.h"
#include "../include/employeesDB.h"

using namespace std;

// get Employee id 
int getEmployeeID(int employeeCount, const employeeClass employeeList[]) {
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
            if (n == employeeList[i].getID()) 
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
void pushEmployee(int& employeeCount, employeeClass employeeList[])
{
    if (employeeCount >= EMPLOYEELISTSIZE) {
        cout << "Employee list is full!\n";
        return;
    }

    string name;
    cout << "EmployeeName: ";
    cin >> name; 

    cin.ignore(10000, '\n');

    cout << "EmployeeID: ";
    int id = getEmployeeID(employeeCount, employeeList);    

    cout << "EmployeeSalary: ";
    int salary = getSalary();

    employeeList[employeeCount].setEmployeeData(name, id, salary);

    cout << "Successfully added new employee";
    employeeCount++;
}

// display all employee
void displayAllEmployees(int employeeCount, const employeeClass employeeList[])
{
    if (employeeCount == 0) {
        cout << "No employees found.\n";
        return;
    }

    for (int i = 0; i < employeeCount; i++) {
        employeeList[i].displayEmployeeData(i + 1);
    }
}

