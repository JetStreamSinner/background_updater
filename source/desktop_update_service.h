#pragma once

#include <string>

class BackgroundUpdateService {
public:
    virtual void update_background(const std::string& image_data) const = 0;
};