#include<iostream>
using namespace std;
int main() 
{
cout << "字符'a' 所占字节数: " << sizeof('a') << endl;
cout << "字符串“a”所占字节数: " << sizeof("a") << endl;
cout << "字符串“China” 所占字节数: " << sizeof("China") << endl;
cout << "整型常量默认为 int，int 型所占字节数: " << sizeof(123) << endl;
cout << "短整型 short 类型所占字节数: " << sizeof(short) << endl;
cout << "float 型数据所占字节数:" << sizeof(float) << endl;
cout << "double 型数据所占字节数:" << sizeof(double) << endl;
cout << "bool 型数据所占的字节数:" << sizeof(bool) << endl;
cout << sizeof(123)<<endl;
cout<<sizeof(1.23)<<endl;
cout<<sizeof(float(1.23))<<endl;
cout<<sizeof(double(1.23))<<endl;
cout << "汉字“中国”所占的字节数 :" << sizeof ( "中国") << endl;
return 0;
}