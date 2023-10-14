#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double temp,tmp;
    double dif_value;
    ofstream out_temp;
    ifstream in_temp;
    //写入文件
    cout<<"请输入第一个温度：\n";
    cin>>temp;
    out_temp.open("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\tempdata.dat");
    out_temp<<temp<<endl;
    for(int i=1;i<6;i++)
    {
        cout<<"请输入第"<<i+1<<"个温度：\n";
        tmp=temp;
        cin>>temp;
        dif_value=tmp-temp;
        out_temp<<temp<<"\t"<<dif_value<<endl;
    }
    out_temp.close();
    //读取文件
    in_temp.open("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\tempdata.dat");
    cout<<"温度"<<"\t"<<"温差\n";
    in_temp>>temp;
    cout<<temp<<endl;
    for(int i=1;i<6;i++)
    {
        in_temp>>temp>>dif_value;
        cout<<temp<<"\t"<<dif_value<<endl;
    }
    in_temp.close();
    return 0;
}