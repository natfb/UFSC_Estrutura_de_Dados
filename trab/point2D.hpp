#include <iostream>

using namespace std;

class Point2D
{
private:
    int *m_x, *m_y;

public:
    Point2D();
    Point2D(int x, int y);
    ~Point2D();

    void SetX(int x);
    void SetY(int y);
    int GetX();
    int GetY();
};


/*#include <iostream>

using namespace std;

class Point2D
{
private:
    int m_x, m_y;

public:
    Point2D();
    Point2D(int x, int y);
    ~Point2D();

    void SetX(int x);
    void SetY(int y);
    int GetX();
    int GetY();
};
*/