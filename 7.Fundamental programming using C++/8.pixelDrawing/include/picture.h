#ifndef PICTURE_H
#define PICTURE_H

#include <string>
#include "../include/shapes.h"

// base class
class shape {
    public: 
        virtual void draw() = 0;

        virtual ~shape() = default;
};

// point 
class point : public shape {
    int x = 1;
    int y = 1;
    ansi::Color color = {255, 255, 255};
    
    public:

    point() = default;

    point(int x, int y, ansi::Color color = {255, 255, 255})
    {
        this-> x = x;
        this-> y = y;
        this-> color = color;
    }

    int getX() const {return x;}
    int getY() const {return y;}
    
    void draw() override;
};

// line
class line : public shape {
    point pointOne;
    point pointTwo;
    ansi::Color color;
    bool filled;

    public:
    line()
    {
        this-> pointOne = point(1, 1);
        this-> pointTwo = point(1, 1);
    }
    line(point pointOne, point pointTwo, ansi::Color color, bool filled)
    {
        this-> pointOne = pointOne;
        this-> pointTwo = pointTwo;
        this-> color = color;
        this->filled = filled;
    }
        void draw() override;
};

// rectangle
class rectangle : public shape {
    point topLeft;
    int hight;
    int width;
    ansi::Color color;
    bool filled;

    public:
        rectangle(point topLeft, int hight, int width, ansi::Color color, bool filled)
        {
            this-> topLeft = topLeft;
            this-> hight = hight;
            this-> width = width;
            this-> color = color;
            this->filled = filled;
        }
        
        void draw() override;
};

// square
class square : public shape {
    point topLeft;
    int length;
    ansi::Color color;
    bool filled;

    public:

        square(point topLeft, int length, ansi::Color color, bool filled)
        {
            this-> topLeft = topLeft;
            this-> length = length;
            this-> color = color;
            this->filled = filled;
        }

        void draw() override;
};

// triangle
class triangle : public shape {
    point pointOne;
    point pointTwo;
    point pointThree;
    ansi::Color color;
    bool filled;

    public:
        triangle(point pointOne, point pointTwo, point pointThree, ansi::Color color, bool filled)
        {
            this-> pointOne = pointOne;
            this-> pointTwo = pointTwo;
            this-> pointThree = pointThree;
            this-> color = color;
            this->filled = filled;
        }

        void draw() override;
}; 

// circle
class circle : public shape {
    point center;
    int redius;
    ansi::Color color;
    bool filled;

    public:
        circle(point center, int redius, ansi::Color color, bool filled)
        {
            this-> center = center;
            this-> redius = redius;
            this-> color = color;
            this->filled = filled;
        }

        void draw() override;
};

// text
class text : public shape {
    point start;
    std::string content;
    ansi::Color color;

    public:
        text(point start, const std::string& content, ansi::Color color = {255, 255, 255})
        {
            this->start = start;
            this->content = content;
            this->color = color;
        }

        void draw() override;
};


#endif