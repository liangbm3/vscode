#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string choice;
    char word[10];
    char encode_word[10],decode_word[10];
    cout<<"文件输入还是键盘输入(输入keyboard或者file)：\n";
    ofstream out_stream;
    cin>>choice;
    //从文件中读取
    if(choice=="file")
    {
        ifstream in_stream;
        in_stream.open("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\keyword.dat");
        in_stream>>word;
        in_stream.close();
    }
    //从键盘中读取
    else if (choice=="keyboard")
    {
        cout<<"请输入一个6个字母长的单词：\n";
        cin>>word;
    }
    else
    {
        cout<<"输入不正确，请重新输入！\n";
    }
    //加密和解密
    if(choice=="file"||choice=="keyboard")
    {
        for(int i=0;i<strlen(word);i++)
        {
            if((word[i]>=65&&word[i]<=90)||word[i]>=97&&word[i]<=122)
            {
            encode_word[i]=word[i]+3;
            decode_word[i]=word[i]-3;
            }
          
            if((word[i]>=120&&word[i]<=122)||(word[i]>=88&&word[i]<=90))
            {
                encode_word[i]=word[i]-23;
            }
            if((word[i]>=65&&word[i]<=67)||(word[i]>=97&&word[i]<=99))
            {
                decode_word[i]=word[i]+23;
            }
        }
    }
    //输出结果
    cout<<"编码结果为："<<encode_word<<endl;
    cout<<"解码结果为："<<decode_word<<endl;
    out_stream.open("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\result.dat");
    out_stream<<"编码结果为："<<encode_word<<endl;
    out_stream<<"解码结果为："<<decode_word<<endl;
    return 0;
}