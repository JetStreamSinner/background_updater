#pragma once

class CliCommand;

class Cli {
public:
    static int execute(const CliCommand& command);
};