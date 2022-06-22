#pragma once

#include <string>
#include <vector>

class CliCommand {
public:
    virtual std::string command() const = 0;
    virtual ~CliCommand() = default;
};