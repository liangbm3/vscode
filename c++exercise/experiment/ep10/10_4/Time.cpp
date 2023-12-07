#include "Time.h"
using namespace std;

Time::Time()
{
    Hour = 0;
    Minute = 0;
    Second = 0;
}
Time::Time(int hour, int minute, int second)
{
    Hour = hour;
    Minute = minute;
    Second = second;
}

Time::Time(Time &T)
{
    Hour = T.Hour;
    Minute = T.Minute;
    Second = T.Second;
}

Time::~Time()
{
    cout << "Good Bye!\n";
}

void Time::SetTime(int hour, int minute, int second)
{
    Hour = hour;
    Minute = minute;
    Second = second;
}

void Time::PrintTime()
{
    cout << Hour << ":" << Minute << ":" << Second << endl;
}