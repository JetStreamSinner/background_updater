#include "scheduler.h"
#include "platforms/gnome/gnome_updater.h"
#include "web_image_provider.h"
#include "application.h"




int main(int argc, char *argv[]) {

    std::unique_ptr<IScheduler> scheduler = std::make_unique<Scheduler>();
    const std::string url = "https://picsum.photos/1920/768";
    std::unique_ptr<ImageProvider> image_source = std::make_unique<WebImageProvider>(url);
    std::unique_ptr<DesktopUpdater> image_updater = std::make_unique<GnomeDesktopUpdater>();

    Application app(scheduler, image_source, image_updater);
    return app.exec();
}