#include "point2D.hpp"
#include <vector>


class Polygon
{
private:
    Point2D* m_vertex;
    //vector< Point2D > m_vertex;

public:
    Polygon();
    Polygon(Point2D *listOfPoint, size_t size){
        m_vertex = new Point2D[size];
        for(size_t i = 0; i < size; i++)
        {
            m_vertex[i] = listOfPoint[i];
        }
    } 
    ~Polygon();

    bool ClearPolygon(){};
    float CalcPerimeter(size_t size);
};

/*
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


*/