#include <iostream>
#include "../include/lib.h"

int getSize(void);

using namespace std;
int main() 
{
    // get box size from user
    cout << "Enter the size of the box: ";
    int boxSize = getSize();

    // Clear the terminal
    cout << "\033[2J"; 

    
    // Siamese method
    siameseMethod(boxSize);

    cout << "\033[" << boxSize * 2 + 1 << ";1H";
    return 0;   
}

int getSize(void)
{
    int boxSize;
    while (!(cin >> boxSize) || boxSize <= 0 || boxSize % 2 == 0)
    {
        cout << "Enter a positive odd number: ";
        cin.clear();
        cin.ignore(100, '\n'); 
    }
    return boxSize;
}

