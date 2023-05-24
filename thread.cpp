#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono> 
#include "timer.h"
using namespace std;

void f_count(int &v, mutex &m) {
    // Lock the mutex before modifying the shared variable
    m.lock();
    v++;
    // Unlock the mutex after modifying the shared variable
    m.unlock();
}


Timer threadTimer;


void threadedVersion(){

    int count = 0, i;

    vector<thread> vt;
    mutex mtx; // Mutex for synchronizing access to count

    threadTimer.startTimer();

    for (i = 0; i < 1000; i++)
        vt.push_back(thread(f_count, ref(count), ref(mtx)));
        this_thread::sleep_for(chrono::milliseconds(10));

    for (i = 0; i < vt.size(); i++)
        vt.at(i).join();

    cout << "Threaded version: "<< count << endl;
    
    threadTimer.endTimer();

}
