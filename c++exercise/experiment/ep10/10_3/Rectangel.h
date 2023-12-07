#include <iostream>
class Rectangel
{
private:
    float len_;
    float wid_;

public:
    Rectangel();
    Rectangel(float len, float wid);
    float get_perimeter();
    float get_area();
    float get_length();
    float get_width();
    void change_length(float len);
    void change_width(float wid);
    void print_rectangel();
    ~Rectangel();
};
