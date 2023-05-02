#include "polygon.hpp"

void Polygon::SetVertex(vector< Point2D > listOfPoint)
{
    m_vertex = listOfPoint;

}

void Polygon::AddPoint2D(Point2D pt)
{
    m_vertex.push_back(pt);
}

bool Polygon::ClearPolygon()
{
    if(m_vertex.size() == 0) return false;

    m_vertex.clear();
    return true;
}

float Polygon::CalcPerimeter()
{

    return 0;
}
