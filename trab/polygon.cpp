#include "polygon.hpp"
#include <cmath>

Polygon::Polygon()
{
    //cout << "Hi, I'm the constructor" << endl;
}
Polygon::~Polygon(){
    ////cout << "Hi, I'm the deconstructor" << endl;
}
/*bool Polygon::ClearPolygon()
{
    if(m_vertex.size() == 0) return false;

    m_vertex.clear();
    return true;
}*/

float Polygon::CalcPerimeter(size_t size)
{
    float per = 0;
    
    for(size_t i = 0; i < size-1; i++)
    {
        Point2D pt1 = m_vertex[i];
        Point2D pt2 = m_vertex[i + 1];
        per += sqrt((pt1.GetX()-pt2.GetX())*(pt1.GetX()-pt2.GetX()) +
        (pt1.GetY()-pt2.GetY())*(pt1.GetY()-pt2.GetY()));
        
    }

    Point2D pt1 = m_vertex[0];
    Point2D pt2 = m_vertex[size - 1];
    per += sqrt((pt1.GetX()-pt2.GetX())*(pt1.GetX()-pt2.GetX()) +
        (pt1.GetY()-pt2.GetY())*(pt1.GetY()-pt2.GetY()));

    return per;
}
