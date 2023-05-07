#include "point2D.hpp"
#include <vector>


class Polygon
{
private:
    Point2D* m_vertex;
    size_t sizet;
    //vector< Point2D > m_vertex;

public:
    Polygon();
    Polygon(Point2D* listOfPoint, size_t size);
    ~Polygon();

    //bool ClearPolygon(){};
    float CalcPerimeter();
    float CalcArea(size_t size);
};

