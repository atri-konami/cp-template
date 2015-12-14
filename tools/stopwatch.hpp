#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

class StopWatch
{   
    system_clock::time_point start,end;

    StopWatch(){}
    ~StopWatch(){}

    void start(){
        start = system_clock.now();
    }

    void end(){
        end = system_clock.now();
    }

    void display(){
        cout << "time: " << duration_cast<milisecond>(end-start).count() << "msec" << endl;
    }
};
