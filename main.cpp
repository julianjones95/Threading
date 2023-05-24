#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono> 
#include "thread.h"
#include "timer.h"

using namespace std;

void unthreadedVersion(){

    Timer threadTimer;
    int count = 0, i;

    threadTimer.startTimer();

    for (i = 0; i < 1000; i++){
        this_thread::sleep_for(chrono::milliseconds(10));
        count++;
    }

    cout << "unthreaded version: " << count << endl;

    threadTimer.endTimer();

}

int main() {
    
    unthreadedVersion();
    threadedVersion();

    return 0;
}

