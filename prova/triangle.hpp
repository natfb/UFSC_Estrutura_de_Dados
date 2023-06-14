#include "shape2d.hpp"
#include "point2d.hpp"

class Triangle : public Shape2D 
{
    private: 
        Point2D p1;
        Point2D p2;
        Point2D p3;
        int size;

    public:
        Triangle() : Shape2D(){};
        Triangle(Point2D p1, int size, Point2D p2, Point2D p3) {};

        float perimeter() {
            return 0;
        };
};

