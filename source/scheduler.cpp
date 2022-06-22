#include "scheduler.h"
#include <thread>

void Scheduler::start(const std::chrono::milliseconds &delay, const std::function<void()>& triggered) {
    while (true) {
        std::this_thread::sleep_for(delay);
        triggered();
    }
}