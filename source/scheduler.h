#pragma once

#include <vector>
#include <functional>
#include <chrono>


class Scheduler {
public:
    explicit Scheduler(const std::function<void()>& exec);
    void start(const std::chrono::milliseconds& delay);
private:
    std::function<void()> _exec;
};