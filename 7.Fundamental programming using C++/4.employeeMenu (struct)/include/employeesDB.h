#ifndef EMPLOYEESDB_H
#define EMPLOYEESDB_H

#include <iostream>
#include <string>

#define EMPLOYEELISTSIZE 2

struct employeeStruct {
    std::string name; 
    int id;
    int salary;

    void displayEmployeeData(int index) const
    {
        std::cout << "Employee " << index << ": " << name << " | ID: " << id << " | Salary: " << salary << '\n';
    }
};


int getEmployeeID(int employeeCount, const employeeStruct employeeList[]);
int getSalary();
void pushEmployee(int listSize, int& employeeCount, employeeStruct employeeList[]);
void popLastEmployee(int& employeeCount, employeeStruct employeeList[]);
void displayAllEmployees(int employeeCount, const employeeStruct employeeList[]);
employeeStruct* resizeList(const int& employeeCount, employeeStruct employeeList[], int newsize);

// class employeeClass {
//     std::string name; 
//     int id;
//     int salary;

//     public:
//         void setEmployeeData(std::string name, int id, int salary)
//         {
//             this-> name = name;
//             this-> id = id;
//             this-> salary = salary;
//         }

//         void displayEmployeeData(int index)
//         {
//             std::cout << "Employee " << index << ": " << name << " | ID: " << id << " | Salary: " << salary << '\n';
//         } 
// };


#endif