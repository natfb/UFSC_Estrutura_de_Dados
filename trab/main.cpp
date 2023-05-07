/*

Trabalho II

Disciplina: Linguagem de Programação II.
Estudantes: Natalia Farias, Alice Motin.

*/

#include "polygon.hpp"
#include <fstream>

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
        cout << "File read complete." <<  endl <<  endl;
    }

    //calcular area com polygon
    Polygon Shape(shapeVertex, numberOfVertex);
    cout << "Shape Area: " << Shape.CalcArea() << endl;

    //calcular perimetro com polygon
    cout << "Shape Perimeter: " << Shape.CalcPerimeter() << endl;
    
    //desalocar memoria
    delete [] shapeVertex;

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
        pointList[i].SetXY(x,y);
    }

    return pointList;
}