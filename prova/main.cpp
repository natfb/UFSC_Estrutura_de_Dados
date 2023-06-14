#include "circle.hpp"
#include "polygonn.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "point2d.hpp"


int main(){
    bool quite = false;
    string answer, type;
    int choice, x, y, c = 0;
    float perimeter;
    size_t radius, edge, size;

    vector <Shape2D*> shapes;
    vector< Point2D > listOfPoints;

    while(choice != 6){
        cout << "UFSC SHAPE MANAGER" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Insert a Circle" << endl;
        cout << "2. Insert a Triangle" << endl;
        cout << "3. Insert a Square" << endl;
        cout << "4. Insert a Polygon" << endl;
        cout << "5. Show Perimeters" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "inset radius: ";
            cin >> radius;
            shapes.push_back(new Circle(radius));
            break;
        case 2:
            while(!quite){
                cout << "inset vertice X: ";
                cin >> x;
                cout << "inset vertice Y: ";
                cin >> y;
                listOfPoints.push_back(Point2D(x,y));
                c++;
                if(c == 3){
                    quite = true;
                }
            }
            shapes.push_back(new Triangle());
            break;

        case 3:

            cout << "inset edge: ";
            cin >> edge;
            shapes.push_back(new Square(edge));
            break;
        case 4:
            while(!quite){
                cout << "inset vertice X: ";
                cin >> x;
                cout << "inset vertice Y: ";
                cin >> y;
                listOfPoints.push_back(Point2D(x,y));
                cout << "All vertices inserted? (y/n): ";
                cin >> answer;
                if(answer == "y"){
                    quite = true;
                }
            }

            shapes.push_back(new Polygon(listOfPoints));
            break;  

        case 5:
            for(int i = 0; i < shapes.size(); i++){
                perimeter = shapes[i]->perimeter();
                type = shapes[i]->getType();
                cout << "Vector Position " << i << " - "<<type << " - Perimeter: " << perimeter << endl;
            }
            break;
        case 6:
            break;
        default:
            break;
        }
    }
    return 0;
}