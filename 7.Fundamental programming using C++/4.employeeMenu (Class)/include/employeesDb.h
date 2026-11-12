#ifndef EMPLOYEESDB_H
#define EMPLOYEESDB_H

#include <string>

#define EMPLOYEEARRAYSIZE 3

using namespace std;
//  prototypes
// struct employeeStruct {
//     char* name; 
//     int id;
//     int salary;
// };

class employeeClass {
    string name; 
    int id;
    int salary;

    public:
        void setEmployeeData(string name, int id, int salary)
        {
            this-> name = name;
            this-> id = id;
            this-> salary = salary;
        }

        void displayEmployeeData(int index)
        {
            cout << "Employee" << index << ": " << name <<"          Employee Id : " << id << "            Employee Salary: " << salary << endl;
        } 
};

#endif
