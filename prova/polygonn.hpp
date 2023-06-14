#include "shape2d.hpp"
#include "point2d.hpp"

class Polygon : public Shape2D 
{

    private:
    vector< Point2D > m_vertex;

    public:
        Polygon() :  Shape2D() {};
        Polygon(vector < Point2D > listOfPoint) : m_vertex(listOfPoint) {};
        ~Polygon() {};

        void SetVertex(vector< Point2D > listOfPoint);
        void AddPoint2D(Point2D pt);

        bool ClearPolygon();
        float CalcPerimeter();

        float perimeter() {
            float per=0;
            for(size_t i=0; i<m_vertex.size()-1; i++)
            {
                Point2D pt1 = m_vertex.at(i);
                Point2D pt2 = m_vertex.at(i+1);

                per += sqrt((pt1.getX()-pt2.getX())*(pt1.getX()-pt2.getX()) +
                (pt1.getY()-pt2.getY())*(pt1.getY()-pt2.getY()));
            }

            Point2D pt1 = m_vertex.at(0);
            Point2D pt2 = m_vertex.at(m_vertex.size()-1);
            per += sqrt((pt1.getX()-pt2.getX())*(pt1.getX()-pt2.getX()) +
                (pt1.getY()-pt2.getY())*(pt1.getY()-pt2.getY()));

            return per;
        };
};