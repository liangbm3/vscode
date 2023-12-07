#include "Time.h"
using namespace std;

int main()
{
    Time time(12, 05, 20);
    time.PrintTime();
    Time time2(time);
    time2.PrintTime();
}