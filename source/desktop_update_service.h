#pragma once

#include "bytes_array.h"

class DesktopUpdateService {
public:
    virtual void update_background(const BytesArray& image_data) const = 0;
};