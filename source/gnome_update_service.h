#pragma once

#include <filesystem>
#include "desktop_update_service.h"

class GnomeDesktopUpdateService : public BackgroundUpdateService {
public:
    void update_background(const std::string& image_data) const override;
private:
    // Move in utils
    void create_temp_directory(const std::filesystem::path& path) const;
};