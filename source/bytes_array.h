#pragma once

#include <cstddef>
#include <vector>
#include <ostream>

class BytesArray {
public:
    explicit BytesArray() = default;
    explicit BytesArray(const char * const raw_buffer, std::size_t buffer_size);
    BytesArray(std::initializer_list<unsigned char>&& init);
    std::size_t size() const;

    std::vector<std::byte>::iterator begin();
    std::vector<std::byte>::iterator end();

    friend std::ostream& operator<<(std::ostream& os, const BytesArray& array);
private:
    std::vector<std::byte> _buffer;
};