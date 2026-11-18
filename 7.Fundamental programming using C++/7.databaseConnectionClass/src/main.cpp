#include <iostream>
#include "../include/databaseConnection.h"

int main()
{
    DatabaseConnection& ref1 = DatabaseConnection::instanceZero();
    DatabaseConnection& ref2 = DatabaseConnection::instanceZero();

    std::cout << (&ref1 == &ref2 ? "Same instance!" : "Different instances!") << std::endl;
}