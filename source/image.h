#pragma once

#include "bytes_array.h"

enum class ImageFormat {
    Png,
    Jpeg,
    Unknown
};

class Image {
public:
    Image() = default;
    explicit Image(const BytesArray& buffer);
    BytesArray data() const;
    ImageFormat format() const;
private:
    BytesArray _buffer;
    ImageFormat _format;
};