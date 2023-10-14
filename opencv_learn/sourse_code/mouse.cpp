#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

Mat src;
int num = 1;
void on_mouse(int event, int x, int y, int flags, void *);
int main()
{
    while (true)
    {

        switch (num)
        {
        case 1:
            src = imread("D:\\vscode\\c++\\opencv_learn\\photo\\1.jpg", 1);
            break;
        case 2:
            src = imread("D:\\vscode\\c++\\opencv_learn\\photo\\2.png", 1);
            break;
        case 3:
            src = imread("D:\\vscode\\c++\\opencv_learn\\photo\\3.jpg", 1);
            break;
        case 4:
            src = imread("D:\\vscode\\c++\\opencv_learn\\photo\\4.png", 1);
            break;
        case 5:
            src = imread("D:\\vscode\\c++\\opencv_learn\\photo\\5.jpg", 1);
            break;
        default:
            break;
        }
        imshow("鼠标事件", src);
        setMouseCallback("鼠标事件", on_mouse, 0);
        waitKey(0);
    }
}
void on_mouse(int event, int x, int y, int flags, void *)
{
    if (event == EVENT_LBUTTONUP && num > 0 && num < 5)
    {
        num += 1;
        destroyWindow("鼠标事件");
    }
    else if (event == EVENT_RBUTTONUP && num > 1 && num < 6)
    {
        num -= 1;
        destroyWindow("鼠标事件");
    }
}
