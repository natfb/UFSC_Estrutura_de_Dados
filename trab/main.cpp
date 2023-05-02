#include "polygon.hpp"
#include <fstream>

//passar pro github  e instalar valgrind
Point2D* ReadShape2DFile(string path, size_t &numberOfVertex);

int main()
{
    cout << "Enter with a shape file name to read (bi-dimensional): ";
    string path; 
    cin >> path;

    size_t numberOfVertex = 0;
    Point2D* shapeVertex = ReadShape2DFile(path, numberOfVertex);
    if(shapeVertex == NULL)
    {
        cout << " *** Error, check filename" << endl;
        return 1;
    }
    else
    {
        cout << "YESSSS, filename " << path << " has " << numberOfVertex << " points" << endl;
        for(size_t i=0; i<numberOfVertex; i++)
        {
            cout << "Point " << i << " -> x: " << shapeVertex[i].GetX() << "  y: " << shapeVertex[i].GetY() << endl;
        }
    }

    //calcular perimetro com polygon
    Polygon Shape(shapeVertex, numberOfVertex);
    cout << "Shape Perimeter: " << Shape.CalcPerimeter(numberOfVertex) << endl;
    
    //calcular perimeter com polygon

    //alocou ? alguem alocou e passou para ti ?   libere o seu lixo aqui !
    delete [] shapeVertex;

    return 0;
};

Point2D* ReadShape2DFile(string path, size_t &numberOfVertex)
{
    ifstream fileReader(path);
    //ifstream fileReader(path.c_str()); //se tiverem problema devido alguma versao de gcc, use this

    if(!fileReader.is_open()) return NULL;

    fileReader >> numberOfVertex;
    Point2D *pointList = new Point2D[numberOfVertex];

    int x, y;
    for(size_t i=0; i<numberOfVertex; i++)
    {
        fileReader >> x;
        fileReader >> y;
        pointList[i].SetX(x);
        pointList[i].SetY(y);
    }

    return pointList;
}
    /*vector< Point2D > listOfPoints;
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
*/