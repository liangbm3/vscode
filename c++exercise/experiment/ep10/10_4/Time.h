#include <iostream>

class Time
{
private:
    int Hour;
    int Minute;
    int Second;

public:
    Time();
    Time(int hour, int minute, int second);
    Time(Time &T);
    void SetTime(int hour, int minute, int second);
    void PrintTime(void);
    ~Time();
};
