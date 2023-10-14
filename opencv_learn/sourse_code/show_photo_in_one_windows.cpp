#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
void showManyImages(const vector<Mat> &srcImages, Size imageSize)
{
    int nNumImages = srcImages.size();
    Size nSizeWindows;
    if (nNumImages > 12)
    {
        cout << "不超过12张图片" << endl;
        return;
    }
    switch (nNumImages)
    {
    case 1:
        nSizeWindows = Size(1, 1);
        break;
    case 2:
        nSizeWindows = Size(2, 1);
        break;
    case 3:
    case 4:
        nSizeWindows = Size(2, 2);
        break;
    case 5:
    case 6:
        nSizeWindows = Size(3, 2);
        break;
    case 7:
    case 8:
        nSizeWindows = Size(4, 2);
        break;
    case 9:
        nSizeWindows = Size(3, 3);
        break;
    default:
        nSizeWindows = Size(4, 3);
        break;
    }
    int nShowImageSize = 200;
    int nAroundLineSize = 50;
    int nSplitLineSize = 15;
    const int imagesHeight = nShowImageSize * nSizeWindows.width + nAroundLineSize + (nSizeWindows.width - 1) * nSplitLineSize;
    const int imagesWidth = nShowImageSize * nSizeWindows.height + nAroundLineSize + (nSizeWindows.height - 1) * nSplitLineSize;
    cout << imagesWidth << " " << imagesHeight << endl;
    Mat showWindowsImages(imagesWidth, imagesHeight, CV_8UC3, Scalar(0, 0, 0));
    int posX = (showWindowsImages.cols - (nShowImageSize * nSizeWindows.width + (nSizeWindows.width - 1) * nSplitLineSize)) / 2;
    int posY = (showWindowsImages.rows - (nShowImageSize * nSizeWindows.height + (nSizeWindows.height - 1) * nSplitLineSize)) / 2;
    cout << posX << " " << posY << endl;
    int tempPosx = posX;
    int tempPosY = posY;
    for (int i = 0; i < nNumImages; i++)
    {
        if (i % nSizeWindows.width == 0 && tempPosx != posX)
        {
            tempPosx = posX;
            tempPosY += (nSplitLineSize + nShowImageSize);
        }
        Mat tempImage = showWindowsImages(Rect(tempPosx, tempPosY, nShowImageSize, nShowImageSize));
        resize(srcImages[i], tempImage, Size(nShowImageSize, nShowImageSize));
        tempPosx += (nSplitLineSize + nShowImageSize);
        imshow("单窗口多图片", showWindowsImages);
        imwrite("234.jpg",showWindowsImages);
    }
}

int main()
{
    vector<Mat> srcImage(9);
    srcImage[0] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\1.jpg");
    srcImage[1] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\2.png");
    srcImage[2] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\3.jpg");
    srcImage[3] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\4.png");
    srcImage[4] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\5.jpg");
    srcImage[5] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\6.jpg");
    srcImage[6] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\7.jpg");
    srcImage[7] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\8.jpg");
    srcImage[8] = imread("D:\\vscode\\c++\\opencv_learn\\photo\\9.jpg");

    for (int i = 0; i < srcImage.size(); i++)
    {
        if (srcImage[i].empty())
        {
            cout << "read error" << endl;
            return -1;
        }
        showManyImages(srcImage, Size(147, 115));
        
        waitKey(0);
        system("pause");
        return 0;
    }
}
