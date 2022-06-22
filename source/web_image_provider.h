#pragma once

#include "image_provider.h"

class WebImageProvider : public ImageProvider {
public:
    explicit WebImageProvider(const std::string &url);
    void set_source(const std::string &url);
    std::string get_source() const;
    Image get_image_data() const override;
    ~WebImageProvider() override = default;
private:
    std::string _url;
};
