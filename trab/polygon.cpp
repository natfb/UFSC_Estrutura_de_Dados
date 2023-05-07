#include "polygon.hpp"
#include <cmath>

Polygon::Polygon()
{
    //cout << "Hi, I'm the constructor" << endl;
}
Polygon::Polygon(Point2D* listOfPoint, size_t size){
    m_vertex = new Point2D[size];
    for(size_t i = 0; i < size; i++)
    {
        m_vertex[i].SetX(listOfPoint[i].GetX()) ;
        m_vertex[i].SetY(listOfPoint[i].GetY()) ;
    }
    sizet = size;
} 
Polygon::~Polygon(){
    cout << "Hi, I'm the deconstructor" << endl;
    if(m_vertex != NULL) {
        delete [] m_vertex;
        //m_vertex = NULL;
        //destrutor de poligon destruindo memoria do set x e y do main 
    }

}
/*bool Polygon::ClearPolygon()
{
    if(m_vertex.size() == 0) return false;

    m_vertex.clear();
    return true;
}*/

float Polygon::CalcPerimeter()
{
    float per = 0;
    
    for(size_t i = 0; i < sizet-1; i++)
    {
        int x, y, x_2, y_2;
        x = m_vertex[i].GetX();
        y = m_vertex[i].GetY();
        x_2 = m_vertex[i + 1].GetX();
        y_2 = m_vertex[i + 1].GetY();
        
        Point2D p1(x, y);
        Point2D p2(x_2, y_2);

        per += sqrt((p1.GetX()-p2.GetX())*(p1.GetX()-p2.GetX()) +
        (p1.GetY()-p2.GetY())*(p1.GetY()-p2.GetY()));

    }

    int x, y, x_2, y_2;
    x = m_vertex[0].GetX();
    y = m_vertex[0].GetY();
    x_2 = m_vertex[sizet - 1].GetX();
    y_2 = m_vertex[sizet - 1].GetY();

    Point2D p1(x, y);
    Point2D p2(x_2, y_2);

    per += sqrt((p1.GetX()-p2.GetX()) * (p1.GetX()-p2.GetX()) +
        (p1.GetY()-p2.GetY()) * (p1.GetY()-p2.GetY()));

    return per;

}

float Polygon::CalcArea(size_t size)
{
    float area = 0;
    Point2D p2(m_vertex[sizet - 1].GetX(), m_vertex[sizet - 1].GetY());
    
    for(size_t i = 0; i < size; i++)
    {
        Point2D p1(m_vertex[i].GetX(), m_vertex[i].GetY());

        area += (p1.GetX() + p2.GetX()) * 
        (p2.GetY() - p1.GetY());
        
        p2.SetX(m_vertex[i].GetX());
        p2.SetY(m_vertex[i].GetY());
    }

    return abs(area / 2.0);
}
