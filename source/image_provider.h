#pragma once

#include "bytes_array.h"

class ImageProvider {
public:
    virtual BytesArray get_image_data() const = 0;
};