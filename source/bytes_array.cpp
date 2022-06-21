#include "bytes_array.h"
#include <algorithm>
#include <cstring>
#include <iterator>

namespace Impl {
    const char * const begin(const char * const raw) {
        return raw;
    }

    const char * const end(const char * const raw, std::size_t buffer_size) {
        return raw + buffer_size - 1;
    }
}

BytesArray::BytesArray(const char * const raw_buffer, std::size_t buffer_size) {
    std::transform(Impl::begin(raw_buffer), Impl::end(raw_buffer, buffer_size), std::back_inserter(_buffer), [](auto init_val) {
        return std::byte(init_val);
    });
}

BytesArray::BytesArray(std::initializer_list<unsigned char> &&init) {
    std::transform(std::begin(init), std::end(init), std::back_inserter(_buffer), [](auto init_val) {
        return std::byte(init_val);
    });
}

std::size_t BytesArray::size() const {
    return _buffer.size();
}

std::vector<std::byte>::iterator BytesArray::begin() {
    return _buffer.begin();
}

std::vector<std::byte>::iterator BytesArray::end() {
    return _buffer.end();
}

std::ostream &operator<<(std::ostream &os, const BytesArray &array) {
    const auto &buffer = array._buffer;
    std::transform(std::begin(buffer), std::end(buffer), std::ostream_iterator<unsigned char>(os), [](const auto &byte) {
        return std::to_integer<unsigned char>(byte);
    });
    return os;
}
