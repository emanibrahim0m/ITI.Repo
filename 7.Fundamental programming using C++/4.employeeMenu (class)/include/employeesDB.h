#ifndef EMPLOYEESDB_H
#define EMPLOYEESDB_H

#include <iostream>
#include <string>

#define EMPLOYEELISTSIZE 2

class employeeClass {
    std::string name; 
    int id;
    int salary;

    public:
        void setEmployeeData(std::string name, int id, int salary)
        {
            this-> name = name;
            this-> id = id;
            this-> salary = salary;
        }
        int getID() const
        {
            return this-> id;
        }

        void displayEmployeeData(int index) const
        {
            std::cout << "Employee " << index << ": " << name << " | ID: " << id << " | Salary: " << salary << '\n';
        } 
};


int getEmployeeID(int employeeCount, const employeeClass employeeList[]);
int getSalary();
void pushEmployee(int& employeeCount, employeeClass employeeList[]);
void popLastEmployee(int& employeeCount, employeeClass employeeList[]);
void displayAllEmployees(int employeeCount, const employeeClass employeeList[]);

#endif