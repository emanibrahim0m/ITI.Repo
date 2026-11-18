#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H 

#include <iostream>

class DatabaseConnection {
    //
    DatabaseConnection() {
        std::cout << "Constructor";
    }

    // dont allow copy constructor & = operator
    DatabaseConnection(DatabaseConnection&) = delete;
    DatabaseConnection& operator=(DatabaseConnection&) =delete;

    // create the only instance
    static DatabaseConnection& instanceZero()
    {
        static DatabaseConnection zero;
        return zero;
    }

    // Methods
    void query() {std::cout << "Hello.";}

};

#endif