#pragma once

#include "../../desktop_updater.h"
#include <filesystem>

class GnomeDesktopUpdater : public DesktopUpdater {
public:
    void update_background(const Image &image_data) const override;
    ~GnomeDesktopUpdater() override = default;
private:
    // Move in utils
    void create_temp_directory(const std::filesystem::path &path) const;
    std::filesystem::path create_filename(ImageFormat format) const;
};