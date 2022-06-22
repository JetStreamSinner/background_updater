#pragma once

#include "image.h"

class DesktopUpdateService {
public:
    virtual void update_background(const Image &image_data) const = 0;
};