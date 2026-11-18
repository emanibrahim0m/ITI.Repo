#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

using namespace std;
#include <iostream>
#include "../include/picture.h"
#include "../include/shapes.h"
#include "../include/app.h"

// track user key presses
char getKeyPress() {
#ifdef _WIN32
    // _getch() reads a single character without echoing or waiting for Enter
    return static_cast<char>(_getch());
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);           // Save current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);         // Disable line buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);  // Apply new settings immediately

    char ch = 0;
    if (read(STDIN_FILENO, &ch, 1) < 0) {
        ch = 0;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  // Restore original settings
    return ch;
#endif
}   

void drawFrame(shape* frame[], int shapeCount)
{
    for (int i = 0; i < shapeCount; i++)
    {
        if(frame[i] != NULL)
        {
            frame[i]-> draw();
        }
    }
}

void deleteFrame(shape* frame[], int shapeCount)
{
    for (int i = 0; i < shapeCount; i++)
    {
        delete frame[i];
    }
}

// Track Key presses
void app()
{   

    ansi::init();

    // General array of child classes
    // First frame
    shape* frameOne[] = {
        // Sky
        new rectangle(point(1, 1),  6, 80, {60, 40, 110}, true),
        new rectangle(point(1, 7),  5, 80, {200, 80, 90}, true),
        new rectangle(point(1, 12), 5, 80, {255, 155, 65}, true),
        // High Sun
        new circle(point(62, 10), 4, {255, 230, 80}, true),
        // Lawn & Path
        new rectangle(point(1, 17), 10, 80, {50, 160, 70}, true),
        new rectangle(point(33, 21), 6, 7, {195, 185, 165}, true),
        // House (Unlit blue daytime windows)
        new triangle(point(36, 6), point(20, 13), point(52, 13), {175, 50, 45}, true),
        new rectangle(point(23, 13), 8, 27, {235, 215, 180}, true),
        new rectangle(point(34, 16), 5, 5, {110, 60, 25}, true),
        new square(point(26, 15), 2, {135, 215, 250}, true),
        new square(point(43, 15), 2, {135, 215, 250}, true),
        // Trees & Fence
        new rectangle(point(10, 14), 5, 2, {100, 55, 20}, true),
        new circle(point(11, 12), 3, {35, 135, 50}, true),
        new text(point(1, 30), "Press 1, 2, 3 to change feame."),
        new text(point(1, 31), "Press q to quit.")
    };

    // second frame
    shape* frameTwo[] = {
        // Deeper Twilight Sky
        new rectangle(point(1, 1),  6, 80, {30, 20, 65}, true),
        new rectangle(point(1, 7),  5, 80, {115, 45, 85}, true),
        new rectangle(point(1, 12), 5, 80, {210, 95, 60}, true),
        // Sinking Sun (lower at y=14)
        new circle(point(62, 14), 4, {255, 140, 50}, true),
        // Darker Lawn & Path
        new rectangle(point(1, 17), 10, 80, {35, 115, 50}, true),
        new rectangle(point(33, 21), 6, 7, {155, 145, 130}, true),
        // House (Warm yellow lights turning on inside)
        new triangle(point(36, 6), point(20, 13), point(52, 13), {140, 40, 35}, true),
        new rectangle(point(23, 13), 8, 27, {200, 180, 150}, true),
        new rectangle(point(34, 16), 5, 5, {90, 50, 20}, true),
        new square(point(26, 15), 2, {255, 220, 100}, true),
        new square(point(43, 15), 2, {255, 220, 100}, true),
        // Trees & Fence
        new rectangle(point(10, 14), 5, 2, {80, 45, 15}, true),
        new circle(point(11, 12), 3, {25, 100, 40}, true),
        new text(point(1, 30), "Press 1, 2, 3 to change feame."),
        new text(point(1, 31), "Press q to quit.")
    };

    // Third frame
    shape* frameThree[] = {
        // Midnight Sky
        new rectangle(point(1, 1), 16, 80, {12, 15, 40}, true),
        // Moon & Stars
        new circle(point(62, 5), 3, {240, 240, 210}, true),
        new point(15, 3, {255, 255, 255}),
        new point(28, 5, {255, 255, 200}),
        new point(48, 3, {255, 255, 255}),
        new point(72, 8, {255, 255, 200}),
        new point(8,  9, {255, 255, 255}),
        // Night Lawn & Path
        new rectangle(point(1, 17), 10, 80, {20, 75, 35}, true),
        new rectangle(point(33, 21), 6, 7, {115, 110, 100}, true),
        // House (Bright glowing windows in the dark)
        new triangle(point(36, 6), point(20, 13), point(52, 13), {105, 30, 30}, true),
        new rectangle(point(23, 13), 8, 27, {150, 135, 115}, true),
        new rectangle(point(34, 16), 5, 5, {70, 35, 15}, true),
        new square(point(26, 15), 2, {255, 240, 120}, true),
        new square(point(43, 15), 2, {255, 240, 120}, true),
        // Trees & Fence
        new rectangle(point(10, 14), 5, 2, {60, 35, 15}, true),
        new circle(point(11, 12), 3, {15, 65, 30}, true),
        new text(point(1, 30), "Press 1, 2, 3 to change feame."),
        new text(point(1, 31), "Press q to quit.")
    };
    

    int shapeOneCount = 15;
    int shapeTwoCount = 15;
    int shapeThreeCount = 18;

    while (true) {
        char key = getKeyPress();

        if (key == '1')
            drawFrame(frameOne, shapeOneCount);
        if (key == '2')
            drawFrame(frameTwo, shapeTwoCount);
        if (key == '3')
            drawFrame(frameThree, shapeThreeCount);
        if (key == 'q')
            break;
    }

    deleteFrame(frameOne, shapeOneCount);
    deleteFrame(frameTwo, shapeTwoCount);
    deleteFrame(frameThree, shapeThreeCount);
}