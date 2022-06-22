#include "scheduler.h"
#include <thread>

Scheduler::Scheduler(const std::function<void()> &exec) : _exec(exec) {
}

void Scheduler::start(const std::chrono::milliseconds &delay) {
    while (true) {
        std::this_thread::sleep_for(delay);
        _exec();
    }
}