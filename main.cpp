#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono> 

using namespace std;

void f_count(int &v, mutex &m) {
    // Lock the mutex before modifying the shared variable
    m.lock();
    v++;
    // Unlock the mutex after modifying the shared variable
    m.unlock();
}

int main() {

    // Using time point and system_clock
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();




    int count = 0, i;

    vector<thread> vt;
    mutex mtx; // Mutex for synchronizing access to count

    for (i = 0; i < 1000; i++)
        vt.push_back(thread(f_count, ref(count), ref(mtx)));
        this_thread::sleep_for(chrono::milliseconds(1000));

    for (i = 0; i < vt.size(); i++)
        vt.at(i).join();

    cout << count << endl;




    end = chrono::system_clock::now();
 
    chrono::duration<double> elapsed_seconds = end - start;
    time_t end_time = chrono::system_clock::to_time_t(end); 
    cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";




    return 0;
}

