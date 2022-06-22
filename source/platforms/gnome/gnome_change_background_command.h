#pragma once

#include "../../cli_command.h"

class GnomeChangeBackgroundCommand : public CliCommand {
public:
    explicit GnomeChangeBackgroundCommand(const std::string &path);
    std::string command() const override;
    ~GnomeChangeBackgroundCommand() override = default;
private:
    bool validate_argument(const std::string &argument) const;
    std::string _path;
};