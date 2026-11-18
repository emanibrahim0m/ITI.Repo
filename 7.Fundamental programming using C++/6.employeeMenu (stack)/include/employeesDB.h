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

class EmployeesStack {

    int size;              
    int capacity;          
    employeeClass* employeeList;

    // helper function for copy
    void copy(const EmployeesStack& other) 
    {
        this-> size = other.size;
        this-> capacity = other.capacity;
        this-> employeeList = new employeeClass[capacity];

        for (int i = 0; i < size; i++) 
            this-> employeeList[i] = other.employeeList[i];
    }

    public:
    // constructor
    EmployeesStack() 
    {
        capacity = EMPLOYEELISTSIZE;
        size = 0;
        employeeList = new employeeClass[capacity];
    }

    // copy constructor
    EmployeesStack(const EmployeesStack& other) 
    {
        copy(other); 
    }

    // = operator to copy
    EmployeesStack& operator=(const EmployeesStack& other) 
    {
        if (this == &other) 
            return *this;

        delete[] employeeList;

        copy(other); 
        return *this;
    }

    // destructor
    ~EmployeesStack() 
    {
        delete[] employeeList;
    }

    // push
    void push(std::string name, int id, int salary) {
        
        if (size == capacity) 
        {
            capacity *= 2;
            employeeClass* old = employeeList;
            employeeList = new employeeClass[capacity];
            for (int i = 0; i < size; i++) 
                employeeList[i] = old[i];

            delete[] old;
        }

        employeeList[size].setEmployeeData(name, id, salary);
        size++;
    }

    // pop 
    void pop() 
    {
        if (size == 0) {
            std::cout << "No employees to remove.\n";
            return;
        }
        size--; 
    }

    // get and set by index
    employeeClass& operator[](int index) {
        if (index < 0 || index >= size) 
            std::cout << "Index out of range";
        return employeeList[index];
    }
    // to pass const obj
    const employeeClass& operator[](int index) const {
        if (index < 0 || index >= size) 
            std::cout << "Index out of range";
        return employeeList[index];
    }

    int getSize() const {return size;}
    int getCapacity() const {return capacity;}
};


int getEmployeeID(EmployeesStack& employeeList);
void getEmployeeData(EmployeesStack& employeeList);
int getSalary();
void displayAllEmployees(const EmployeesStack& employeeList);

#endif