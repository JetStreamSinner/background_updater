#pragma once

#include <chrono>
#include <functional>

class IScheduler {
public:
    virtual void start(const std::chrono::milliseconds& delay, const std::function<void()>& triggered) = 0;
    virtual ~IScheduler() = default;
};