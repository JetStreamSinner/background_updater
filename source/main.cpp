#include <fstream>
#include "curl_download_service.h"
#include "gnome_update_service.h"
#include "scheduler.h"



int main(int argc, char * argv[])
{
    const std::string url = "https://thisisthewall.herokuapp.com/api";
    auto exec = [&]() {
        CURLDownloadService service(url);
        const std::string data = service.get_image_data();
        GnomeDesktopUpdateService update_service;
        update_service.update_background(data);

    };
    Scheduler scheduler(exec);
    scheduler.start(std::chrono::milliseconds(1000));

    return 0;
}