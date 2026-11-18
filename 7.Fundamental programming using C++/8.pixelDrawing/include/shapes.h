#ifndef SHAPES_H
#define SHAPES_H

#include <string>

namespace ansi {struct Color { int r, g, b; };}

class point;

namespace ansi {
    void init();
    void cleanup(int exit_row = 25);
    void clear();
    void draw_pixel(point point, Color c, const std::string& ch = "█");
    void draw_text(point start, const std::string& text, Color c = {255, 255, 255});
    void draw_line(point pointOne, point pointTwo, Color c, const std::string& ch = "█");
    void draw_rect(point topLeft, int w, int h, Color c, bool filled = false);
    void draw_circle(point center, int r, Color c, bool filled = false);
    void draw_square(point topLeft, int size, Color c, bool filled = false);
    void draw_triangle(point pointOne, point pointTwo, point pointThree, Color c, bool filled = false);

} // namespace ansi

#endif