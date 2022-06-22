#include "platforms/gnome/gnome_update_service.h"
#include "scheduler.h"
#include "utils.h"
#include "web_image_provider.h"
#include <fstream>


int main(int argc, char *argv[]) {
    const std::string url = "https://picsum.photos/1920/768";
    auto exec = [&]() {
        WebImageProvider service(url);
        const auto data = service.get_image_data();
        GnomeDesktopUpdateService update_service;
        update_service.update_background(data);
    };
    Scheduler scheduler(exec);
    scheduler.start(std::chrono::milliseconds(1000));

    return 0;
}