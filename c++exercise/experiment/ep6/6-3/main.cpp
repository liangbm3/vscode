#include "mytriangle.h"
#include <iostream>
using namespace std;
int main()
{    
    double a,b,c;
    cout<<"请输入三角形三边的长：\n";
    cout<<"a=";
    cin>>a;
    cout<<"\nb=";
    cin>>b;
    cout<<"\nc=";
    cin>>c;
    if(is_valid(a,b,c))
    {
        cout<<"三角形的面积为："<<area(a,b,c);
    }
    else
    {
        cout<<"输入的三边不能组成三角形！\n";
    }
}