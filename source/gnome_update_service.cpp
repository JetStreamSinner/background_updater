#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include "gnome_update_service.h"

void GnomeDesktopUpdateService::update_background(const std::string &image_data) const {
    const std::filesystem::path path = std::filesystem::absolute("out.png");
    std::fstream out(path, std::ios::out | std::ios::trunc);

    if (!out.is_open()) {
        return;
    }

    out.write(image_data.c_str(), image_data.size());
    out.close();

    std::stringstream ss;
    const std::string update_command = "gsettings set org.gnome.desktop.background picture-uri ";
    ss << update_command << path;
    system(ss.str().c_str());
}