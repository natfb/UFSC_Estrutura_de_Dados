#include "point2D.hpp"
#include <vector>

class Polygon
{
private:
    Point2D* m_vertex;
    size_t sizet;

public:
    Polygon() {};
    Polygon(Point2D* listOfPoint, size_t size);
    ~Polygon();

    float CalcPerimeter();
    float CalcArea();
};

