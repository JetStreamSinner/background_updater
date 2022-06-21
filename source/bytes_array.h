#pragma once

#include <cstddef>
#include <vector>
#include <ostream>

class BytesArray {
public:
    BytesArray() = default;
    BytesArray(char * raw_buffer);
    BytesArray(std::initializer_list<unsigned char>&& init);
    std::size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const BytesArray& array);
private:
    std::vector<std::byte> _buffer;
};