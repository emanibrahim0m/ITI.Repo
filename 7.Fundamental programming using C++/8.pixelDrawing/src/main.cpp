#include <iostream>
#include "../include/picture.h"
#include "../include/shapes.h"
#include "../include/app.h"

using namespace ansi;
#define SHAPECOUNT 20

int main() {
    ansi::init();
    // call app
    app();

    ansi::cleanup(30);
    return 0;
}
