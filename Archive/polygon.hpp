#include "point2D.hpp"
#include <vector>


class Polygon
{
private:
    vector< Point2D > m_vertex;

public:
    Polygon() {};
    Polygon(vector< Point2D > listOfPoint) : m_vertex(listOfPoint) {};
    ~Polygon() {};

    void SetVertex(vector< Point2D > listOfPoint);
    void AddPoint2D(Point2D pt);

    bool ClearPolygon();
    float CalcPerimeter();

};
