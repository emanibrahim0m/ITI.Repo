#include "shapes.h"
#include <iostream>
#include <cmath>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

#include "../include/picture.h"

namespace ansi {

void init() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    std::cout << "\x1b[2J\x1b[?25l" << std::flush;
}

void cleanup(int exit_row) {
    std::cout << "\x1b[" << exit_row << ";1H\x1b[0m\x1b[?25h" << std::flush;
}

void clear() {
    std::cout << "\x1b[2J\x1b[H" << std::flush;
}

// pixel
void draw_pixel(point pt, Color c, const std::string& ch) {
    int x = pt.getX();
    int y = pt.getY();
    if (x < 1 || y < 1) return;

    std::cout << "\x1b[" << y << ";" << x << "H"
              << "\x1b[38;2;" << c.r << ";" << c.g << ";" << c.b << "m"
              << ch << "\x1b[0m";
}

// text
void draw_text(point start, const std::string& text, Color c) {
    int x = start.getX();
    int y = start.getY();
    if (x < 1 || y < 1) return;

    std::cout << "\x1b[" << y << ";" << x << "H"
              << "\x1b[38;2;" << c.r << ";" << c.g << ";" << c.b << "m"
              << text << "\x1b[0m";
}

// line
void draw_line(point pointOne, point pointTwo, Color c, const std::string& ch) {
    int x0 = pointOne.getX(), y0 = pointOne.getY();
    int x1 = pointTwo.getX(), y1 = pointTwo.getY();

    int dx = std::abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -std::abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (true) {
        draw_pixel(point(x0, y0), c, ch);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// rectangle
void draw_rect(point topLeft, int w, int h, Color c, bool filled) {
    int x = topLeft.getX();
    int y = topLeft.getY();

    if (filled) {
        for (int row = y; row < y + h; ++row) {
            for (int col = x; col < x + w; ++col) {
                draw_pixel(point(col, row), c);
            }
        }
    } else {
        draw_line(point(x, y), point(x + w - 1, y), c);
        draw_line(point(x, y + h - 1), point(x + w - 1, y + h - 1), c);
        draw_line(point(x, y), point(x, y + h - 1), c);
        draw_line(point(x + w - 1, y), point(x + w - 1, y + h - 1), c);
    }
}

// circle
void draw_circle(point center, int r, Color c, bool filled) {
    if (r <= 0) return;
    int cx = center.getX();
    int cy = center.getY();
    const double aspect = 2.0;
    int rx = static_cast<int>(std::round(r * aspect));
    for (int y = cy - r; y <= cy + r; ++y) {
        for (int x = cx - rx; x <= cx + rx; ++x) {
            double dx = (x - cx) / aspect;
            double dy = (y - cy);
            double dist = std::sqrt(dx * dx + dy * dy);
            if (filled) {
                if (dist <= r + 0.25) {
                    draw_pixel(point(x, y), c);
                }
            } else {
                if (std::abs(dist - r) < 0.55) {
                    draw_pixel(point(x, y), c);
                }
            }
        }
    }
}


// square
void draw_square(point topLeft, int size, Color c, bool filled) {
    draw_rect(topLeft, size * 2, size, c, filled);
}

// triangle
void draw_triangle(point pointOne, point pointTwo, point pointThree, Color c, bool filled) {
    if (!filled) {
        draw_line(pointOne, pointTwo, c);
        draw_line(pointTwo, pointThree, c);
        draw_line(pointThree, pointOne, c);
        return;
    }

    int x0 = pointOne.getX(), y0 = pointOne.getY();
    int x1 = pointTwo.getX(), y1 = pointTwo.getY();
    int x2 = pointThree.getX(), y2 = pointThree.getY();

    if (y0 > y1) { std::swap(x0, x1); std::swap(y0, y1); }
    if (y0 > y2) { std::swap(x0, x2); std::swap(y0, y2); }
    if (y1 > y2) { std::swap(x1, x2); std::swap(y1, y2); }

    auto draw_span = [&](int y, int xa, int xb) {
        if (xa > xb) std::swap(xa, xb);
        for (int x = xa; x <= xb; ++x) {
            draw_pixel(point(x, y), c);
        }
    };

    int total_height = y2 - y0;
    if (total_height == 0) {
        draw_span(y0, std::min({x0, x1, x2}), std::max({x0, x1, x2}));
        return;
    }

    for (int i = 0; i <= total_height; ++i) {
        bool second_half = i > (y1 - y0) || y1 == y0;
        int segment_height = second_half ? (y2 - y1) : (y1 - y0);
        if (segment_height == 0) continue;

        double alpha = static_cast<double>(i) / total_height;
        double beta  = static_cast<double>(i - (second_half ? (y1 - y0) : 0)) / segment_height;

        int ax = x0 + static_cast<int>(std::round((x2 - x0) * alpha));
        int bx = second_half
                 ? x1 + static_cast<int>(std::round((x2 - x1) * beta))
                 : x0 + static_cast<int>(std::round((x1 - x0) * beta));

        draw_span(y0 + i, ax, bx);
    }
}

} // namespace ansi
