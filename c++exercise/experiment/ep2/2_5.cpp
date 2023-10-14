#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.1415926
int main()
{
    double a,b,c,d,E,f,g,h,i,j;
    cout<<"abs(-100.01)="<<abs(-100.01)<<endl;
    a=-1.82021;
    cout<<"求实数的绝对值："<<fabs(a)<<endl;
    b=6.6;
    cout<<"求实数的平方根："<<sqrt(b)<<endl;
    c=2.3;
    cout<<"求不大于某数的最大整数，向下取整："<<floor(c)<<endl;
    d=4.3;
    cout<<"求不小于某数的最小整数，向下取整："<<ceil(d)<<endl;
    E=100;
    cout<<"E的以e为底的对数为："<<log(E)<<endl;
    cout<<"e的E次方为："<<exp(E)<<endl;
    g=pow(3,4);
    cout<<"3的4次方为："<<g<<endl;
    h=PI;
    cout<<sin(h/6)<<" "<<tan(h/4)<<endl;
    cout<<asin(0)<<" "<<asin(-0.3)<<endl;
    cout<<"round(10.45753)="<<round(10.45753)<<endl;
    return 0;
}