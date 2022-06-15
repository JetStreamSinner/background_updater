#include "curl_download_service.h"
#include "platforms/gnome/gnome_update_service.h"
#include "scheduler.h"
#include "utils.h"
#include <fstream>


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
    scheduler.start(std::chrono::hours(1));

    return 0;
}