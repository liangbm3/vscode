#include<graphics.h>
#include<conio.h>
#include<string>

enum {shiftingx=150,shiftingy=100,wide=372,length=425};
const int gridx = (wide - 20) / 8;
const int gridy = (length - 20) / 9;

int main()
{
    initgraph(720, 640);// 初始化 720x640 的绘图屏幕
    setorigin(150, 100); //设置坐标原点

     //画外边框
    setlinestyle(PS_SOLID,3);
    rectangle(0,0,wide,length);
    setfillcolor(RGB(219, 195, 35));
    fillrectangle(0, 0, wide, length);
    
     //画横线
    for(int i=0;i<10;i++)
    {
        line(0, i * gridy, 8 * gridx, i * gridy);
    }
     //画竖线
    for(int i=0;i<9;i++)
    {
        line(i * gridx, 0, i * gridx, 4 * gridy); //上方的线段
        line(i * gridx, 5 * gridy, i * gridx, 9 * gridy);//下方的线段（跨过河流）
    }

     //画象棋特殊分割线
    line(3 * gridx, 0 * gridy, 5 * gridx, 2 * gridy);
    line(3 * gridx, 2 * gridy, 5 * gridx, 0 * gridy);
    line(3 * gridx, 7 * gridy, 5 * gridx, 9 * gridy);
    line(3 * gridx, 9 * gridy, 5 * gridx, 7 * gridy);

    getch(); // 等待键盘输入
    closegraph(); // 关闭绘图窗口
    return 0;
}