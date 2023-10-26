#include "mytriangle.h"

bool is_valid(double side1, double side2, double side3)
{
    double max_side;
    double min_side;
    double mid_side;
    if (side1 >= side2)
    {
        max_side = side1;
        min_side = side2;
    }
    else
    {
        max_side = side2;
        min_side = side1;
    }
    if (max_side < side3)
    {
        mid_side = max_side;
        max_side = side3;
    }
    else if (min_side > side3)
    {
        mid_side = min_side;
        min_side = side3;
    }
    else
    {
        mid_side = side3;
    }
    if ((mid_side + min_side) > max_side)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double area(double side1, double side2, double side3)
{
    double s = (side1 + side2 + side3) / 2.0;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}