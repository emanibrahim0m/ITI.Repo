#ifndef EMPLOYEESDB_H
#define EMPLOYEESDB_H

#include <string>
#include "../include/utils.h"

using namespace std;
//  prototypes
struct employeeStruct {
    string name; 
    int id;
    int salary;

    void setEmployeeData()
    {
        cout << "EmployeeName: ";
        cin >> name;
        cout << "EmployeeID: ";
        this-> id = getInt();
        cout << "EmployeeSalary: ";
        this-> salary = getInt();
    }

    void displayEmployeeData(int index)
    {
        cout << "Employee" << index << ": " << name <<"             Employee Id : " << id << "              Employee Salary: " << salary << endl;
    }
};

// class employeeClass {
//     string name; 
//     int id;
//     int salary;

//     public:
//         void setEmployeeData(string name, int id, int salary)
//         {
//             this-> name = name;
//             this-> id = id;
//             this-> salary = salary;
//         }

//         void displayEmployeeData(int index)
//         {
//             cout << "Employee" << index << ": " << name <<"          Employee Id : " << id << "            Employee Salary: " << salary << endl;
//         } 
// };

#endif
