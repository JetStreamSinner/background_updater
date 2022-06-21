#pragma once

#include "bytes_array.h"
enum class ImageFormat;


class ImageResolver {
public:
    ImageFormat resolve(BytesArray &array) const;
private:
    bool match_png(BytesArray &array) const;
    bool match_jpeg(BytesArray &array) const;
    bool match_signature(BytesArray& signature, BytesArray &array) const;
};