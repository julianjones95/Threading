#pragma once
using namespace std;


class Timer{

    public:
    // Using time point and system_clock
    chrono::time_point<chrono::system_clock> start, end;

    void startTimer();

    void endTimer();

};

