#pragma once

class CliCommand;

class CliTerminal {
public:
    int execute(const CliCommand &command);
};