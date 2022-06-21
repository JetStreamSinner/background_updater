#pragma once

#include <string>

class ImageProvider {
public:
    virtual std::string get_image_data() const = 0;
};