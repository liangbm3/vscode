#include "mytemperature.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "\t";
    for (int i = 0; i < 50; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "\t\t"
         << "摄氏温度Celsiu华氏温度Fahrenheit转换\n";
    cout << "\t";
    for (int i = 0; i < 50; i++)
    {
        cout << "*";
    }
    cout << "\nCelsius\tFahrenheit\t|\tFahrenheit\tCelsius\n";
    cout << 40.0 << "\t" << celsius_to_fah(40.0) << "\t\t|\t" << 120.0 << "\t\t" << fahrenheit_to_cel(120.0) << endl;
    cout << 39.0 << "\t" << celsius_to_fah(39.0) << "\t\t|\t" << 110.0 << "\t\t" << fahrenheit_to_cel(110.0) << endl;
}