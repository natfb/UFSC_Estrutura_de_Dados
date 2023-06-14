#include "shape2d.hpp"
#include "point2d.hpp"

class Triangle : public Shape2D 
{
    private: 
        Point2D p1;
        Point2D p2;
        Point2D p3;

    public:
        Triangle() : Shape2D(){};
        Triangle(Point2D p1, Point2D p2, Point2D p3) : p1(p1), p2(p2), p3(p3) {};

        float perimeter() {
            float per=0;
            per = pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2) +
                pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2) +
                pow(p3.getX() - p1.getX(), 2) + pow(p3.getY() - p1.getY(), 2);
            return per;
        };
        
        string getType() {
            return "Triangle";
        };
};

