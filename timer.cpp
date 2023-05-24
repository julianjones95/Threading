#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono> 
#include "timer.h"

using namespace std;

chrono::time_point<chrono::system_clock> start, end;

void Timer::startTimer() {
    start = chrono::system_clock::now();

}

void Timer::endTimer() {
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = chrono::system_clock::to_time_t(end); 
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
    
}


