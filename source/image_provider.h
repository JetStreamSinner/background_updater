#pragma once

#include "image.h"

class ImageProvider {
public:
    virtual Image get_image_data() const = 0;
};