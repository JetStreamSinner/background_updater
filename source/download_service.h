#pragma once

#include <string>

class DownloadService {
public:
    virtual std::string get_image_data() const = 0;
};