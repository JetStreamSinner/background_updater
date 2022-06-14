#pragma once

#include "desktop_update_service.h"

class GnomeDesktopUpdateService : public BackgroundUpdateService {
public:
    void update_background(const std::string& image_data) const override;
};