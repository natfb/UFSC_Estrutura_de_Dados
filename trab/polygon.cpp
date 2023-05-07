#include "polygon.hpp"
#include <cmath>

Polygon::Polygon(Point2D* listOfPoint, size_t size){
    m_vertex = new Point2D[size];
    
    for(size_t i = 0; i < size; i++){
        m_vertex[i].SetXY(listOfPoint[i].GetX(), listOfPoint[i].GetY());
    }

    sizet = size;
} 
Polygon::~Polygon(){
    if(m_vertex != NULL) delete [] m_vertex;
}

float Polygon::CalcPerimeter()
{
    float per = 0;
    
    for(size_t i = 0; i < sizet - 1; i++)
    {     
        Point2D p1(m_vertex[i].GetX(), m_vertex[i].GetY());
        Point2D p2(m_vertex[i + 1].GetX(), m_vertex[i + 1].GetY());

        per += sqrt((p1.GetX()-p2.GetX())*(p1.GetX()-p2.GetX()) +
        (p1.GetY()-p2.GetY())*(p1.GetY()-p2.GetY()));
    }

    Point2D p1(m_vertex[0].GetX(), m_vertex[0].GetY());
    Point2D p2(m_vertex[sizet - 1].GetX(), m_vertex[sizet - 1].GetY());

    per += sqrt((p1.GetX()-p2.GetX()) * (p1.GetX()-p2.GetX()) +
        (p1.GetY()-p2.GetY()) * (p1.GetY()-p2.GetY()));

    return per;
}

float Polygon::CalcArea()
{
    float area = 0;
    Point2D p2(m_vertex[sizet - 1].GetX(), m_vertex[sizet - 1].GetY());
    
    for(size_t i = 0; i < sizet; i++)
    {
        Point2D p1(m_vertex[i].GetX(), m_vertex[i].GetY());

        area += (p1.GetX() + p2.GetX()) * (p2.GetY() - p1.GetY());
        
        p2.SetXY(m_vertex[i].GetX(), m_vertex[i].GetY());
    }

    return abs(area / 2.0);
}