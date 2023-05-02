#include "polygon.hpp"
#include <cmath>
//comando gdb para ver seg fault gdb ./out r bt
void Polygon::SetVertex(vector< Point2D > listOfPoint)  ///point pointer p / point2d *??, size t quantidade | poligon::poligon
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
    float per=0;
    for(size_t i=0; i<m_vertex.size()-1; i++)
    {
        Point2D pt1 = m_vertex.at(i);
        Point2D pt2 = m_vertex.at(i+1);

        per += sqrt((pt1.GetX()-pt2.GetX())*(pt1.GetX()-pt2.GetX()) +
        (pt1.GetY()-pt2.GetY())*(pt1.GetY()-pt2.GetY()));
    }

    Point2D pt1 = m_vertex.at(0);
    Point2D pt2 = m_vertex.at(m_vertex.size()-1);
    per += sqrt((pt1.GetX()-pt2.GetX())*(pt1.GetX()-pt2.GetX()) +
        (pt1.GetY()-pt2.GetY())*(pt1.GetY()-pt2.GetY()));

    return per;
}
