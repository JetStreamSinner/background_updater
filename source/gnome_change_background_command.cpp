#include <sstream>
#include "gnome_change_background_command.h"

GnomeChangeBackgroundCommand::GnomeChangeBackgroundCommand(const std::string& path) : _path(path) {
    const bool arguments_bad = validate_argument(_path);
    if (arguments_bad) {
        std::runtime_error("Bad arguments");
    }
}

bool GnomeChangeBackgroundCommand::validate_argument(const std::string& argument) const {
    // Check path in argument?
    return false;
}

std::string GnomeChangeBackgroundCommand::command() const {
    const std::string command_base = "gsettings set org.gnome.desktop.background picture-uri ";
    std::stringstream path_builder(command_base);
    path_builder << _path;
    return path_builder.str();
}