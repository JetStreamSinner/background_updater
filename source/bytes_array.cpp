#include "bytes_array.h"
#include <algorithm>
#include <iterator>
#include <cstring>

char * begin(char * raw) {
    return raw;
}

char * end(char * raw) {
    return raw + strlen(raw) - 1;
}

BytesArray::BytesArray(char * raw_buffer) {
    std::transform(begin(raw_buffer), end(raw_buffer), std::back_inserter(_buffer), [](auto init_val) {
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

std::ostream& operator<<(std::ostream& os, const BytesArray& array) {
    const auto& buffer = array._buffer;
    std::transform(std::begin(buffer), std::end(buffer), std::ostream_iterator<unsigned char>(os), [](const auto& byte) {
        return std::to_integer<unsigned char>(byte);
    });
    return os;
}
