#include "Rectangel.h"
using namespace std;
Rectangel::Rectangel()
{
    len_ = 0;
    wid_ = 0;
}

Rectangel::Rectangel(float len, float wid)
{
    len_ = len;
    wid_ = wid;
}

Rectangel::~Rectangel()
{
}

void Rectangel::change_length(float len)
{
    len_ = len;
}

void Rectangel::change_width(float wid)
{
    wid_ = wid;
}

float Rectangel::get_length()
{
    return len_;
}

float Rectangel::get_width()
{
    return wid_;
}

float Rectangel::get_perimeter()
{
    return 2 * (len_ + wid_);
}

float Rectangel::get_area()
{
    return len_ * wid_;
}

void Rectangel::print_rectangel()
{
    cout << "length:" << len_ << ",width:" << wid_ << endl;
}