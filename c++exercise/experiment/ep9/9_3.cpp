#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
};

int menu_fun()
{
    int choice;
    while (1)
    {

        cout << "***********************************\n";
        cout << "\t1.Circle(圆)\n";
        cout << "\t2.Rectangle(长方形)\n";
        cout << "\t0.Exit(退出)\n";
        cout << "***********************************\n";
        cout << "请输入你的选择：";
        cin >> choice;
        if (choice == 1 || choice == 2 || choice == 0)
        {
            return choice;
        }
        else
        {
            cout << "你的输入不合法，请按照菜单输入！\n";
        }
    }
}
void draw_rec_fun(Point start_point, Point end_point)
{
    int a;
    for (int i = 0; i <= end_point.y; i++)
    {

        if (i < start_point.y)
        {
            cout << endl;
        }
        else if (i == start_point.y || i == end_point.y)
        {

            for (int j = 0; j <= end_point.x; j++)
            {
                if (j < start_point.x)
                {
                    cout << "  ";
                }
                else
                {
                    cout << "* ";
                }
            }
            cout << "\n";
        }
        else
        {
            for (int j = 0; j <= end_point.x; j++)
            {
                if (j == start_point.x)
                {
                    cout << "*";
                }
                else if (j == end_point.x)
                {
                    cout << " *";
                }
                else
                    cout << "  ";
            }
            cout << "\n";
        }
    }
}
void draw_circle_fun(Point start_point, Point end_point)
{
    if (end_point.x - start_point.x != end_point.y - start_point.y)
    {
        cout << "画圆时所给坐标必须构成正方形！\n";
        return;
    }
    else
    {
        Point center_point;
        float r = (float)(end_point.x - start_point.x) / 2;
        center_point.x = (start_point.x + end_point.x) / 2;
        center_point.y = (start_point.y + end_point.y) / 2;
        float x0 = center_point.x;
        float y0 = center_point.y;
        int x;
        for (int y = 0; y <= end_point.y; y++)
        {
            if (y < start_point.y)
            {
                cout << endl;
            }
            else
            {
                for (int x = 0; x <= end_point.x; x++)
                {
                    if ((x == (int)(pow(pow(r, 2) - pow((float)y - y0, 2), 0.5) + x0)) || (x == (int)(-pow(pow(r, 2) - pow((float)y - y0, 2), 0.5) + x0)))
                    {
                        cout << " *";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
    }
}
Point get_xy_fun()
{
    int point_x, point_y;
    Point point;
    cin >> point_x >> point_y;
    point.x = point_x;
    point.y = point_y;
    return point;
}
int main()
{
    Point start_point, end_point;
    while (true)
    {
        switch (menu_fun())
        {
        case 0:
            return 1;
        case 1:
            cout << "请输入起点坐标：(先输入x后输入y)";
            start_point = get_xy_fun();
            cout << "请输入终点坐标：(先输入x后输入y)";
            end_point = get_xy_fun();
            draw_circle_fun(start_point, end_point);
            break;
        case 2:
            cout << "请输入起点坐标：(先输入x后输入y)";
            start_point = get_xy_fun();
            cout << "请输入终点坐标：(先输入x后输入y)";
            end_point = get_xy_fun();
            draw_rec_fun(start_point, end_point);
            break;
        default:
            break;
        }
    }
}
