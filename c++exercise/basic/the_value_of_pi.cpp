/* ------------------------------- 泰勒展开式计算pi的值 ------------------------------ */

#include <iostream>
#include <cmath>
using namespace std;

int n;
double total = 0;
bool continue_ = true;
char command;
void menu(void);

int main()
{

	while (continue_ == true)
	{
		cout << "请输入n的值求Pi\n";
		cin >> n;
		if (n > 0)
		{
			for (double t = 1; t <= n; t++)
			{
				total = total + pow(-1, (t + 1)) / (2 * t - 1);
			}
			cout << "n=" << n << "时，";
			cout << "Pi的近似值为" << 4 * total << endl;
			menu();
		}
		else
		{
			cout << "请输入大于零的n值\n";
		}
	}
	cout << "计算结束！";
}

void menu(void)
{
	cout << "是否继续计算（Y/N）\n";
	cin >> command;
	switch (command)
	{
	case 'y':
	case 'Y':
		continue_ = true;
		total = 0;
		break;
	case 'n':
	case 'N':
		continue_ = false;
		break;
	default:
		menu();
	}
}