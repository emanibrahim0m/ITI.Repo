#ifndef OPERATOROVERLOADING_H
#define OPERATOROVERLOADING_H

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
            return 1;
        }
        return pointXY(x / other.x, y / other.y);
    }

    void getPoints() const
    {
        cout << "X= " << x << " Y= " << y << endl;
    }
};

#endif
