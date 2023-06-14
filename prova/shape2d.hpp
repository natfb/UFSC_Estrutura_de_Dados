#ifndef SHAPE2D_HPP
#define SHAPE2D_HPP

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape2D
{
    private: 
        string type;
    public:
        Shape2D(){};

    virtual float perimeter()  = 0;
    virtual string getType() = 0;     
};

#endif