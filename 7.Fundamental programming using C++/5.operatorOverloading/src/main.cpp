#include <iostream>
#include "../include/lib.h"

using namespace std;

int main() {
    int x, y, j, k;
    cout << "Enter x, y, j, k" << endl;
    cin >> x >> y >> j >> k;
    pointXY XYpoint(x,y);
    pointXY JKpoint(j,k);

    pointXY LMpoint= XYpoint + JKpoint;
    LMpoint.getPoints();

    LMpoint= XYpoint - JKpoint;
    LMpoint.getPoints();

    LMpoint= XYpoint * JKpoint;
    LMpoint.getPoints();

    LMpoint= XYpoint / JKpoint;
    LMpoint.getPoints();
}
