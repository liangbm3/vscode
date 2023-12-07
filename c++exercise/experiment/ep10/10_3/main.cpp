#include "Rectangel.h"
using namespace std;

int main()
{
    Rectangel rec1(20, 35.2);
    cout << "矩形的长为：" << rec1.get_length() << ",宽为：" << rec1.get_width() << ",周长为：" << rec1.get_perimeter() << ",面积为：" << rec1.get_area() << endl;
    rec1.print_rectangel();
    rec1.change_length(20.5);
    rec1.change_width(33);
    cout << "矩形的长为：" << rec1.get_length() << ",宽为：" << rec1.get_width() << ",周长为：" << rec1.get_perimeter() << ",面积为：" << rec1.get_area() << endl;
    Rectangel rec2;
    cout << "矩形的长为：" << rec2.get_length() << ",宽为：" << rec2.get_width() << ",周长为：" << rec2.get_perimeter() << ",面积为：" << rec2.get_area() << endl;
    rec2.print_rectangel();
    rec2.change_length(20);
    rec2.change_width(25);
    cout << "矩形的长为：" << rec2.get_length() << ",宽为：" << rec2.get_width() << ",周长为：" << rec2.get_perimeter() << ",面积为：" << rec2.get_area() << endl;
    rec2.print_rectangel();
}