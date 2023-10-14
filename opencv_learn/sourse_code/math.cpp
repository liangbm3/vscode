#include<opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main()
{
    cout<<"cvRound是四舍五入(满6进位）\n";
    cout<<"cvRound(2.4):"<<cvRound(2.4)<<endl;
    cout<<"cvRound(2.5):"<<cvRound(2.5)<<endl;
    cout<<"cvRound(2.6):"<<cvRound(2.6)<<endl;
    cout<<"cvRound(2.8):"<<cvRound(2.8)<<endl;
    cout<<"cvFloor是向下取整\n";
    cout<<"cvFloor(2.5):"<<cvFloor(2.5)<<endl;
    cout<<"cvFloor(2.6):"<<cvFloor(2.6)<<endl;
    cout<<"cvCeil是向上取整\n";
    cout<<"cvCeil(2.5):"<<cvCeil(2.5)<<endl;
    cout<<"cvCeil(2.5):"<<cvCeil(2.5)<<endl;

}