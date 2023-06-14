#include "shape2d.hpp"

class Square : public Shape2D 
{
    private:
        size_t edge;
    public:
        Square() : Shape2D(){};
        Square(size_t edge) : edge(edge) {};

        float perimeter() {
            return 4 * edge;
        };
        
        string getType() {
            return "Square";
        };
};