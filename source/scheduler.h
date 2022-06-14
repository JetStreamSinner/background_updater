#pragma once

#include <vector>
#include <functional>
#include <chrono>


class Scheduler {
public:
    explicit Scheduler(const std::function<void()>& exec);
    void start(const std::chrono::duration<double, std::ratio<1, 10>>& delay);
private:
    std::function<void()> _exec;
};