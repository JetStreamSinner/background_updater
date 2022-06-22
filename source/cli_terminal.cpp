#include "cli_terminal.h"
#include "cli_command.h"

int CliTerminal::execute(const CliCommand &command) {
    const int execution_error_code = system(command.command().c_str());
    return execution_error_code;
}