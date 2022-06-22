#pragma once

#include <chrono>
#include <functional>
#include <vector>
#include "i_scheduler.h"


class Scheduler : public IScheduler {
public:
    void start(const std::chrono::milliseconds &delay, const std::function<void()>& exec) override;
    ~Scheduler() override = default;
};