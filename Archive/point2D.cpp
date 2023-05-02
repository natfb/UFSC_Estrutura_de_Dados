#include "point2D.hpp"


Point2D::Point2D()
{
    //cout << "Hi, I'm the constructor" << endl;
}

Point2D::Point2D(int x, int y)
{
    //cout << "Hi, I'm the param constructor" << endl;
    this->m_x = x; //escolher se com this->, ou sem
    m_y = y;
}

Point2D::~Point2D()
{
    //cout << "Hi, I'm the desconstructor. I want to kill it" << endl;
}

void Point2D::SetX(int x)
{
    m_x = x;
}

void Point2D::SetY(int y)
{
    m_y = y;
}

int Point2D::GetX()
{
    return m_x;
}

int Point2D::GetY()
{
    return m_y;
}
