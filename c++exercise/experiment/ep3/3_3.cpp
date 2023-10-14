#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()

{
    double x;
    int i, j;
    ofstream outfile1("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\test1.dat");
    ofstream outfile2("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\test2.dat");
    i = 36;
    j = 123;
    x = 45467.89;
    outfile1 << i<<" ";
    outfile1 << j<<" ";
    outfile1 << x;
    outfile1.close();
    cout << "From first file i=" << i << ",j=" << j << ",x=" << x << endl;

    i = 12;
    j = 168;
    x = 89.99;
    outfile2 << i<<" ";
    outfile2 << j<<" "<<x;
    outfile2.close();
    cout << "From second file i=" << i << ",j=" << j << ",x=" << x << endl;
    ifstream infile1("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\test1.dat");
    ifstream infile2("D:\\vscode\\c++\\c++exercise\\experiment\\ep3\\filetest\\test2.dat");
    infile1>>i;
    infile1>>j>>x;
    infile1.close();
    cout << "From first file i=" << i << ",j=" << j << ",x=" << x << endl;
    infile2 >> i;
    infile2 >> j >> x;
    infile2.close();
    cout << "From second file i=" << i << ",j=" << j << ",x=" << x << endl;
    return 0;
}