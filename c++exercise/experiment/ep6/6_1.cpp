#include <iostream>
using namespace std;

int j = 40;
void p()
{
    int i = 5;
    static int j = 5;
    i++;
    j++;
    cout << "i is " << i << endl;
    cout << "j is " << j << endl;
}

int main()
{
    cout << j << endl;
    p();
    cout << "j=" << j << endl;
    p();
    return 0;
}