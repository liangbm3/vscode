#include <graphics.h>
#include <conio.h>
 
int main()
{
	initgraph(640, 480);
	circle(320, 240, 100);
	getch();
	closegraph();
	return 0;
}