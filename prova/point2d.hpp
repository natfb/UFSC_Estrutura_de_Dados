#ifndef POINT2D_HPP
#define POINT2D_HPP
#include <iostream>

using namespace std;

class Point2D
{
    private:
        int x;
        int y;
    public:
        Point2D(){};
        Point2D(int x, int y) : x(x), y(y) {};
        int getX() { return x; };
        int getY() { return y; };
};
#endif