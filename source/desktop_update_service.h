#pragma once

#include <string>

class DesktopUpdateService {
public:
    virtual void update_background(const std::string& image_data) const = 0;
};