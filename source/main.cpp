#include <fstream>
#include "curl_download_service.h"
#include "gnome_update_service.h"



int main(int argc, char * argv[])
{
    const std::string url = "https://thisisthewall.herokuapp.com/api/ru";
    CURLDownloadService service(url);
    const std::string data = service.get_image_data();

    GnomeDesktopUpdateService update_service;
    update_service.update_background(data);

    return 0;
}