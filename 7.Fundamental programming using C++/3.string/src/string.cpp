#include <iostream>
#include "../include/lib.h"

using namespace std;

int main() 
{
    char stringOne[] = "Hello!";
    char stringTwo[] = "Bye!";
    char stringThree[] = "Hello!";
    
    // to upper
    toupperString(stringOne);
    cout << "ToUpper: " << stringOne << endl;
    
    // to lower
    toLowerString(stringOne);
    cout << "ToLower: " << stringTwo << endl;
    
    // string compare 'case sensitive'
    bool isIdentical = compareString(stringOne, stringThree);
    if (isIdentical)
        cout << "V1: String one is identical to String two.\n";
    else
        cout << "V1: String One is not identical to String two\n";
    // Version2
    bool isIdenticalTwo = compareString(stringOne, stringThree);
    if (isIdenticalTwo)
        cout << "V2: String one is identical to String two.\n";
    else
        cout << "V2: String One is not identical to String two\n";
    
    
    // string length
    int length = stringLength(stringOne);
    cout << "Length: " << length << endl;

    // string copy
    char stringFour[length - 6];
    copyString(stringOne, stringFour);
    cout << stringFour << endl;
    
    return 0;
}
