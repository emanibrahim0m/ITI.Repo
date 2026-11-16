#ifndef OPERATOROVERLOADING_H
#define OPERATOROVERLOADING_H

#include <cstddef>
#include <iostream>

using namespace std;
class pointXY {
    int x;
    int y;

    public:
    // constractor
    pointXY(int x = 0, int y = 0) {
        this-> x = x;
        this-> y = y;
    }

    // + Operator
    pointXY operator+ (const pointXY& other) const 
    {
        return pointXY(x + other.x, y + other.y);
    }

    friend pointXY operator+ (const pointXY& point, int n);

    // - Operator
    pointXY operator- (const pointXY& other) const 
    {
        return pointXY(x - other.x, y - other.y);
    }

    // * Operator
    pointXY operator* (const pointXY& other) const 
    {
        return pointXY(x * other.x, y * other.y);
    }

    // / Operator
    pointXY operator/ (const pointXY& other) const 
    {
    	if (other.x == 0 || other.y == 0) {
            cout << "Division by zero.";
            return pointXY(0, 0);
        }
        return pointXY(x / other.x, y / other.y);
    }

    // % n
    pointXY& operator% (int n) 
    {
        this-> x %= n;
        this-> y %= n;
        return *this;
    }

    // % point
    pointXY operator% (const pointXY& other) const  
    {
        return pointXY(this-> x % other.x, this-> y % other.x);
    }

    friend pointXY operator% (const pointXY& other, int n);

    // () swap 
    void operator() ()
    {
        int tmp = this-> x;
        this-> x = this-> y;
        this-> y = tmp;
        return;
    }

    // [] index
    int operator[] (int n)
    {
        if (n == 0)
            return this-> x;
        else if (n == 1)
            return this-> y;
        else 
            cout << "Wrong Index";
    }

    // ++ prefix / --
    pointXY& operator++ ()
    {
        ++this-> x;
        ++this-> y;
        return *this;
    }

    // ++ postfix / --  
    pointXY operator++ (int)
    {
        pointXY tmp(x, y);
        this-> x++;
        this-> y++;
        return tmp;
    }

    // == 
    bool operator== (const pointXY& other) const
    {
        if ((this-> x == other.x) && (this-> y == other.y))
            return true;
        return false;
    }

    // !=
    bool operator== (const pointXY& other) const
    {
        if ((this-> x != other.x) && (this-> y != other.y))
            return true;
        return false;
    }

    // = 
    pointXY& operator= (const pointXY& other) 
    {
        if (this == &other) return *this; // Guard against self-assignment
        this-> x = other.x; 
        this-> y = other.y;
        return *this; 
    }

    // !
    bool operator! () 
    {
        if (this-> x == 0 && this-> y == 0)
            return true;
        return false;
    }

    // &&   
    bool operator&& (const pointXY& other)
    {
        bool right = (this-> x == other.x);
        bool left = (this-> y== other.y);

        return right && left;
    }

    // || 
    bool operator|| (const pointXY& other)
    {
        bool right = (this-> x == other.x);
        bool left = (this-> y== other.y);

        return right || left;
    }

    // new
    void* operator new (size_t size)
    {
        return ::operator new(size);
    }

    // delete 
    void operator delete (void* ptr) noexcept
    {
        return ::operator delete(ptr);
    }

    // istream - ostream
    friend ostream& operator<< (ostream& stream, pointXY& other);
    friend istream& operator>> (istream& stream, pointXY& other);


    void getPoints() const
    {
        cout << "X= " << x << " Y= " << y << endl;
    }
};

#endif
