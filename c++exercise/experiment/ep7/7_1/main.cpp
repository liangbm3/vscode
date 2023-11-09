#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LetterCount(string line);
void LineCount(istream &file, int &count);

int main()
{
    ifstream inFile;
    inFile.open("D:\\vscode\\c++\\c++exercise\\experiment\\ep7\\7_1\\test.dat");
    int count = 0;
    LineCount(inFile, count);
    cout << "Number of lines:" << count << endl;
    return 0;
}

void LetterCount(string line)
{
    int count = line.length();
    cout << "has" << count << "characters;\n";
}

void LineCount(istream &file, int &count)
{
    string line;
    while (!file.eof())
    {
        getline(file, line);
        count++;
        cout << "Line" << count;
        LetterCount(line);
    }
}