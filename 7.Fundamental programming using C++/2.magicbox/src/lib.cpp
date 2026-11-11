#include <iostream>
#include <chrono>
#include <thread>
#include "../include/lib.h"

using namespace std;

// move curser
void move_point(int x, int y, int number)
{
    y = y * 4;
    x = x * 2;
    cout << "\033[" << x << ";" << y << "H" << number << flush;
}

void siameseMethod(int boxSize)
{
    // sum and number initialization
    int sum = boxSize * boxSize;


    // number position
    int positionX = boxSize / 2 + 1;
    int positionY = 1;

    // print numbers
    for (int i = 0; i < sum; i++) 
    {
        // first number in the middle of the top row
        move_point(positionY, positionX, i + 1);
        std::this_thread::sleep_for(250ms); 

        if ((i + 1) % boxSize == 0)
            positionY ++;
            // not needed
            // if (positionY > boxSize)
            //     positionY = 1;
        else 
        {
            positionY --;
            positionX ++;

            if (positionY < 1)
                positionY = boxSize;
            if (positionX > boxSize)
                positionX = 1;
        }
    }
}
