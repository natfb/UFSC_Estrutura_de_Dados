#include "point2D.hpp"

Point2D::Point2D()
{
    m_x=m_y=NULL;
}

Point2D::Point2D(int x, int y)
{
    m_x = new int;
    m_y = new int;
   *m_x=x;
   *m_y=y;

}

Point2D::~Point2D()
{
    if(m_x != NULL) delete m_x;
    if(m_x != NULL) delete m_y;
}

void Point2D::SetX(int x)
{
    if(m_x==NULL) m_x = new int;
    *m_x = x;
}

void Point2D::SetY(int y)
{
    if(m_y==NULL) m_y = new int;
    *m_y = y;
}
int Point2D::GetX()
{
    return *m_x;
}

int Point2D::GetY()
{
    return *m_y;
}
/*
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
*/