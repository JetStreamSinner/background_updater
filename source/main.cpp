#include <fstream>
#include "curl_download_service.h"



int main(int argc, char * argv[])
{
    const std::string url = "https://thisisthewall.herokuapp.com/api/ru";
    CURLDownloadService service(url);
    const std::string data = service.get_image_data();
    std::fstream out("out.png", std::ios::out);

    if (!out.is_open()) {
        return -1;
    }

    out.write(data.c_str(), data.size());
    out.close();

    return 0;
}