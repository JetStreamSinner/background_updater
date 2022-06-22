#pragma once

#include "../../desktop_updater.h"
#include <filesystem>

class GnomeDesktopUpdateService : public DesktopUpdater {
public:
    void update_background(const Image &image_data) const override;

private:
    // Move in utils
    void create_temp_directory(const std::filesystem::path &path) const;
    std::filesystem::path create_filename(ImageFormat format) const;
};