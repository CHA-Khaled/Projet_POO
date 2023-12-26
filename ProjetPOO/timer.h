#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer {
public:
    void start();
    void stop();
    void print(const std::string& message = "");

private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point stop_time;
};

#endif
