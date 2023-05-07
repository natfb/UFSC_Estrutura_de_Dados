#include "polygon.hpp"
#include <fstream>

//passar pro github  e instalar valgrind
Point2D* ReadShape2DFile(string path, size_t &numberOfVertex);

int main()
{
    cout << "Enter with a shape file name to read (bi-dimensional): ";
    string path; 
    //path = "square.txt"; 
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
    cout << "Shape Perimeter: " << Shape.CalcPerimeter() << endl;
    
    //calcular perimeter com polygon
    cout << "Shape Area: " << Shape.CalcArea(numberOfVertex) << endl;

    //alocou ? alguem alocou e passou para ti ?   libere o seu lixo aqui !
    delete [] shapeVertex;
    //shapeVertex = NULL;
    
    return 0;
}

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
