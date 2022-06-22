#include "image_resolver.h"
#include "image.h"
#include <algorithm>

ImageFormat ImageResolver::resolve(BytesArray &array) const {
    if (bool png_format = match_png(array); png_format) {
        return ImageFormat::Png;
    } else if (bool jpeg_format = match_jpeg(array); jpeg_format) {
        return ImageFormat::Jpeg;
    }
    return ImageFormat::Unknown;
}

bool ImageResolver::match_png(BytesArray &array) const {
    BytesArray png_signature = {137, 80, 78, 71, 13, 10, 26, 10};
    return match_signature(png_signature, array);
}

bool ImageResolver::match_jpeg(BytesArray &array) const {
    BytesArray jpeg_signature = {0xFF, 0xD8, 0xFF};
    return match_signature(jpeg_signature, array);
}

bool ImageResolver::match_signature(BytesArray &signature, BytesArray &array) const {
    auto miss_iterator = std::mismatch(std::begin(signature), std::end(signature), std::begin(array));
    auto signature_iterator = miss_iterator.first;
    return signature_iterator == signature.end();
}