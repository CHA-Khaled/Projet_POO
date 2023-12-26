#include "timer.h"

void Timer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void Timer::stop() {
    stop_time = std::chrono::high_resolution_clock::now();
}

void Timer::print(const std::string& message) {
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop_time - start_time);
    std::cout << message << " Time: " << duration.count() << " ms\n";
}
