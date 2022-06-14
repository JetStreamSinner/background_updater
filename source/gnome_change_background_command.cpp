#include <sstream>
#include <filesystem>
#include <regex>
#include "gnome_change_background_command.h"

GnomeChangeBackgroundCommand::GnomeChangeBackgroundCommand(const std::string& path) : _path(path) {
    const bool arguments_bad = validate_argument(_path);
    if (arguments_bad) {
        std::runtime_error("Bad arguments");
    }
}

bool GnomeChangeBackgroundCommand::validate_argument(const std::string& argument) const {
    const bool path_exist = std::filesystem::exists(argument);
    const std::regex png_pattern("\\/?(?:[^\"'/]+\\/)+[^\"'\\s]+?\\.png\\b");
    const bool match_png = std::regex_match(argument, png_pattern);
    return !(path_exist && match_png);
}

std::string GnomeChangeBackgroundCommand::command() const {
    const std::string command_base = "gsettings set org.gnome.desktop.background picture-uri ";
    std::stringstream path_builder;
    path_builder << command_base << _path;
    return path_builder.str();
}