#include <iostream>
#include "../include/lib.h"

using namespace std;

// To upper
void toupperString(char* stringOne)
{
    int counter = 0;
    while (stringOne[counter] != '\0')
    {
        if (stringOne[counter] >= 'a' && stringOne[counter] <= 'z')
            stringOne[counter] -= ('a' - 'A');
        counter++;
    }
}

// To lower
void toLowerString(char* stringOne)
{
    int counter = 0;
    while (stringOne[counter] != '\0')
    {
        if (stringOne[counter] >= 'A' && stringOne[counter] <= 'Z')
            stringOne[counter] += ('a' - 'A');
        counter++;
    }
}

// Compare based on ascii 'case sensitive'
bool compareString(char* stringOne, char* stringTwo)
{
    int length = 0;

    while (stringOne[length] == stringTwo[length])
    {
        if (stringOne[length] == '\0')
            return true;
        length++; 
    }
    return false;
}

// Length
int stringLength(char* stringOne)
{
    int length = 0;
    while (stringOne[length] != '\0')
        length++;
    return length;
}

// Copy
void compareCopy(char* stringOne, char* stringTwo, int length)
{
    for (int i = 0; i <= length + 1; i++)
        stringTwo[i] = stringOne[i];
}