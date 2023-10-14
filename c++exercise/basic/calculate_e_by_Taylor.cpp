/* ------------------------- 通过泰勒展开式计算e的x次方，并和函数库比较 ------------------------- */
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;
int main()
{
	SetConsoleOutputCP(65001);
	float x;
	float total1 = 0, total2 = 0;
	cout << "请输入x的值" << endl;
	cin >> x;
	for (int t = 0; t < 100; t++)
	{
		double m = 1;

		if (t != 0)
		{
			for (int n = t; n > 1; n--)
			{
				m = m * n;
				cout << "m=" << m << endl;
			}
		}
		total1 = total1 + pow(x, t) / m;
		cout << "total=" << total1 << endl;
		cout << "t=" << t << endl;
	}
	cout << "泰勒展开计算得到的值为" << total1 << endl;
	cout << "函数库的值为" << exp(x);
	cout << "相对误差为" << (total1 - exp(x)) << endl;
	return 0;
}