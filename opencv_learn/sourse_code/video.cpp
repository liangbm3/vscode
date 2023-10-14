#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
    VideoCapture cap("D:\\vscode\\c++\\opencv_learn\\video\\1.mp4");
    if (!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    string imgPath = "D:\\vscode\\c++\\opencv_learn\\photo\\1.jpg";
    while (true)
    {
        cap >> frame;
        if (frame.empty())
        {
            break;
        }
        imshow("播放视频", frame);
        if (waitKey(30) == 27)
            break;
        else if (waitKey(30) == 32)
        {
            while (waitKey(0) != 32)
                waitKey(0);
        }
    }
}