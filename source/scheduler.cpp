#include <thread>
#include "scheduler.h"

Scheduler::Scheduler(const std::function<void()>& exec) : _exec(exec) {

}

void Scheduler::start(const std::chrono::duration<double, std::ratio<1, 10>>& delay) {
    while (true) {
        std::this_thread::sleep_for(delay);
        _exec();
    }
}