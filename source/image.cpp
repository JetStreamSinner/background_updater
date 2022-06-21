#include "image.h"
#include "image_resolver.h"

Image::Image(const BytesArray &buffer) : _buffer(buffer) {
    ImageResolver resolver;
    _format = resolver.resolve(_buffer);
    if (_format == ImageFormat::Unknown) {
        throw std::runtime_error("Unknown image type");
    }
}

BytesArray Image::data() const {
    return _buffer;
}

ImageFormat Image::format() const {
    return _format;
}