#include "shape2d.hpp"

class Circle : public Shape2D 
{
    private:
        size_t ratio;
    public:
        Circle() : Shape2D(){};
        Circle(size_t ratio) : ratio(ratio){};
        
        float perimeter(){
            return 2 * ratio * 3.14;
        };
        string getType(){
            return "Circle";
        }
};