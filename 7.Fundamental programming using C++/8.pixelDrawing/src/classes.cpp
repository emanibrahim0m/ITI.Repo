#include <iostream>
#include "../include/shapes.h"
#include "../include/picture.h"

using namespace std;

void point::draw() {
    ansi::draw_pixel(*this, color);
}

void line::draw() {
    ansi::draw_line(pointOne, pointTwo, color);
}

void rectangle::draw() {
    ansi::draw_rect(topLeft, width, hight, color, filled);
}

void square::draw() {
    ansi::draw_square(topLeft, length, color, filled);
}

void triangle::draw() {
    ansi::draw_triangle(pointOne, pointTwo, pointThree, color, filled);
}

void circle::draw() {
    ansi::draw_circle(center, redius, color, filled);
}

void text::draw() {
    ansi::draw_text(start, content, color);
}

