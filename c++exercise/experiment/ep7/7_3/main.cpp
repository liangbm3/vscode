#include <iostream>
#include <string>
#include <complex>
using namespace std;

int main()
{
    float num[5];
    char m;
    cout << "please input a,b,c,and use space to separate them:";
    int i = 0;
    while ((m = getchar()) != '\n')
    {
        if (m != ' ')
        {
            ungetc(m, stdin);
            cin >> num[i++];
        }
    }
    float a = num[0];
    float b = num[1];
    float c = num[2];
    float det = b * b - 4 * a * c;
    if (det > 0)
    {
        float x1 = (-b - sqrt(det)) / (2 * a);
        float x2 = (b - sqrt(det)) / (2 * a);
        cout << "x1=" << x1 << ",x2=" << x2 << endl;
    }
    else if (det == 0)
    {
        float x;
        x = (-b - sqrt(det)) / (2 * a);
        cout << "x1=x2=" << x << endl;
    }
    if (det < 0)
    {
        complex<double> complex_det(det, 0);
        float x1_real = (-b + sqrt(complex_det).real()) / (2 * a);
        float x1_imag = sqrt(complex_det).imag() / (2 * a);
        float x2_real = (b + sqrt(complex_det).real()) / (2 * a);
        float x2_imag = sqrt(complex_det).imag() / (2 * a);
        cout << "x1=" << x1_real << "+" << x1_imag << "i,"
             << "x2=" << x2_real << "+" << x2_imag << "i";
    }
}