#include "polygon.hpp"

int main()
{
    //primeira forma de inicializar um polygon
    vector< Point2D > listOfPoints;
    listOfPoints.push_back(Point2D(0,0));
    listOfPoints.push_back(Point2D(10,30));
    listOfPoints.push_back(Point2D(30,20));
    listOfPoints.push_back(Point2D(40,10));
    listOfPoints.push_back(Point2D(30,0));
    listOfPoints.push_back(Point2D(15,10));

    //Polygon instance
    Polygon Shape1(listOfPoints);
    cout << "Shape 1: " << Shape1.CalcPerimeter() << endl;

    //segunda forma de inicializar um polygon
    vector< Point2D > listOfPoints2;
    listOfPoints2.push_back(Point2D(0,0));
    listOfPoints2.push_back(Point2D(0,10));
    listOfPoints2.push_back(Point2D(10,10));
    listOfPoints2.push_back(Point2D(10,0));
    Polygon Shape2;
    Shape2.SetVertex(listOfPoints2);
    cout << "Shape 2: " << Shape2.CalcPerimeter() << endl;

    //terceira forma de inicializar um polygon
    Polygon Shape3;
    Shape3.AddPoint2D(Point2D(0,0));
    Shape3.AddPoint2D(Point2D(0,2));
    Shape3.AddPoint2D(Point2D(2,2));
    Shape3.AddPoint2D(Point2D(2,0));
    cout << "Shape 3: " << Shape3.CalcPerimeter() << endl;

    Shape3.ClearPolygon();
    Shape3.AddPoint2D(Point2D(0,0));
    Shape3.AddPoint2D(Point2D(0,10));
    Shape3.AddPoint2D(Point2D(10,0));
    cout << "Shape 3: " << Shape3.CalcPerimeter() << endl;


    return 0;
};
