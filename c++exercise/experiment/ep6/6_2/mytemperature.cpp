#include "mytemperature.h"

double celsius_to_fah(double cel)
{
    double fah;
    fah = 9 * cel / 5.0 + 32;
    return fah;
}

double fahrenheit_to_cel(double fah)
{
    double cel;
    cel = 5 * (fah - 32) / 9.0;
    return cel;
}