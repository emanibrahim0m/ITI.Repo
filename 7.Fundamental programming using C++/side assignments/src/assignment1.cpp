#include <iostream> 

using namespace std;

/*
(1) Write a program that take two integers 
from the user and print the results of this equation:
Result = ((num1 + num2) * 3) – 10
*/

int assignment1()
{
    cout << "Enter two numbers: ";
    int x, y;
    cin >> x >> y;
    if (cin.fail() || x < 0 || y < 0) 
    {
        cout << "Invalid Numbers.";
        return 1;
    }

    int result = ((x + y) * 3) - 10;
    return result;
}


/*
(11) Print sum of first 100 integers. (With data validation)
*/

int assignment11()
{
    int size;
    while (!(cin >> size) || size < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a valid input: "; 
    }
    int result = 0;
    for (int i = size; i > 0; i--)
    {
        result+= i;
    }
    return result;
}




/*
(19) Write a program to display inverted half pyramid using
stars pattern.
* * * * *
* * * *
* * *
* *
*
*/

void assignment19(int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}