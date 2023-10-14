#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    const double xigema=8.85e-12;//ε值
    const double landa=1.7e-7;//λ值
    double r =6e-2;//半径r
    double z=0.04;//z值
    double E=(landa*z*r)/(2*xigema*pow((pow(z,2)+pow(r,2)),(3/2)));
    cout << "电场为" << E<<endl;
    return 0;
}



