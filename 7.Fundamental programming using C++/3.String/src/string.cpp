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
        cout << "String one is identical to String two.\n";
    else
        cout << "String One is not identical to String two\n";
    
    
    // string length
    int length = stringLength(stringOne);
    cout << "Length: " << length << endl;

    // string copy
    char stringFour[length + 1];
    compareCopy(stringOne, stringFour, length);
    cout << stringFour << endl;
    
    return 0;
}
