#include <fstream>
#include <iostream>
#include "gnome_change_background_command.h"
#include "cli.h"
#include <filesystem>
#include "gnome_update_service.h"

void GnomeDesktopUpdateService::update_background(const std::string &image_data) const {
    const std::filesystem::path path = std::filesystem::absolute("out.png");
    std::fstream out(path, std::ios::out | std::ios::trunc);

    if (!out.is_open()) {
        // throw error?
        return;
    }

    out.write(image_data.c_str(), image_data.size());
    out.close();

    GnomeChangeBackgroundCommand command(path);
    Cli::execute(command);
}