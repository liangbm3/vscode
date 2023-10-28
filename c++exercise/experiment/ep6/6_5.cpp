#include <graphics.h>
#include <conio.h>
#include <string>

enum
{
    shiftingx = 150,
    shiftingy = 100,
    wide = 372,
    length = 425
};

const int gridx = (wide - 20) / 8;
const int gridy = (length - 20) / 9;

using namespace std;

int main()
{
    initgraph(720, 640);
    setorigin(shiftingx, shiftingy);
    setlinestyle(PS_SOLID, 3);
    rectangle(0, 0, wide, length);
    setfillcolor(RGB(219, 195, 35));
    fillrectangle(0, 0, wide, length);
    fillrectangle(10, 10, wide - 10, length - 10);
    for (int i = 1; i <= 7; i++)
    {
        line(10 + i * gridx, 10, 10 + i * gridx, length - 10);
        setbkmode(TRANSPARENT);
        fillrectangle(10, 10 + 4 * gridy, wide - 10, 10 + 5 * gridy);
    }
    for (int i = 1; i <= 8; i++)
    {
        line(10, 10 + i * gridy, wide - 10, 10 + i * gridy);
    }
    RECT r = {10 + 44, 10 + 4 * gridy, 10 + 44 * 3, 10 + 5 * gridy};
    RECT a = {10 + 44 * 4, 10 + 4 * gridy, 10 + 44 * 7, 10 + 5 * gridy};
    drawtext(_T("楚 河"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("汉 界"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    line(10 + 3 * gridx, 10, 10 + 5 * gridx, 10 + 2 * gridy);
    line(10 + 5 * gridx, 10, 10 + 3 * gridx, 10 + 2 * gridy);
    line(10 + 3 * gridx, length - 10, 10 + 5 * gridx, length - 10 - gridy * 2);
    line(10 + 5 * gridx, length - 10, 10 + 3 * gridx, length - 10 - gridy * 2);
    _getch();
    closegraph();
}