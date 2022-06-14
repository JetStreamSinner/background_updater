#pragma once

#include "download_service.h"

class CURLDownloadService : public DownloadService {
public:
    explicit CURLDownloadService(const std::string& url);
    void set_source(const std::string& url);
    std::string get_source() const;
    std::string get_image_data() const override;
private:
    std::string _url;
};
