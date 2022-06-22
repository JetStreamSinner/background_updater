#pragma once

#include "image.h"

class DesktopUpdater {
public:
    virtual void update_background(const Image &image_data) const = 0;
};