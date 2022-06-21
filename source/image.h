#pragma once

#include "bytes_array.h"

enum class ImageFormat {
    Png,
    Jpeg,
    Unknown
};

struct Image {
    BytesArray buffer;
    ImageFormat format;
    Image() = default;
    explicit Image(const BytesArray& buffer, ImageFormat format) : buffer(buffer), format(format) {

    }
};