#include <fstream>
#include <string>
#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    string line;
    ifstream file_in;
    file_in.open("D:\\vscode\\c++\\c++exercise\\experiment\\ep7\\7_4\\lyrics.dat");
    while (!file_in.eof())
    {
        getline(file_in, line);
        cout << line << endl;
        usleep(500000);
    }
}