#include <iostream>
using namespace std;
class TPoint
{
private:
    int m_x;
    int m_y;

public:
    TPoint();
    TPoint::TPoint(int x);
    TPoint(int x, int y);
    TPoint(TPoint &p);
    ~TPoint();
    int get_x();
    int get_y();
};

TPoint::TPoint()
{
    m_x = 0;
    m_y = 0;
    cout << "Constructor is called" << endl;
}

TPoint::TPoint(int x)
{
    m_x = x;
    cout << "Constructor is called" << endl;
}

TPoint::TPoint(int x, int y)
{
    m_x = x;
    m_y = y;
    cout << "Constructor is called" << endl;
}

TPoint::TPoint(TPoint &p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    cout << "Copy-initialization Constructor is called" << endl;
}

TPoint::~TPoint()
{
    cout << "Destructor is called" << endl;
}

int TPoint::get_x()
{
    return m_x;
}

int TPoint::get_y()
{
    return m_y;
}

int main()
{
    TPoint p0;
    TPoint p1(4, 9);
    TPoint p2(p1);
    TPoint p3(p2);
    cout << "p3=(" << p3.get_x() << "," << p3.get_y() << ")" << endl;
}