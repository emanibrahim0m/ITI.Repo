#include <iostream>
#include "../include/class.h"

using namespace std;

// ostream
ostream& operator<< (ostream& stream, pointXY& other)
{
    stream << "PointX: " << other.x << endl;
    stream << "PointY: " << other.y << endl;
    return stream;
}

// istream
istream& operator>> (istream& stream, pointXY& other)
{
    stream >> other.x;
    stream >> other.y;
    return stream;
}

// n + - * /
pointXY operator+ (const pointXY& point, int n) 
{
    return pointXY(point.x + n, point.y + n);
}

// n % 
pointXY operator% (const pointXY& other, int n)  
{
    return pointXY(n % other.x, n % other.y);
}