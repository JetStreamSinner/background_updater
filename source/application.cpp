#include "application.h"

#include "i_scheduler.h"
#include "image_provider.h"
#include "desktop_updater.h"

Application::Application(std::unique_ptr<IScheduler> &scheduler, std::unique_ptr<ImageProvider> &provider, std::unique_ptr<DesktopUpdater> &updater) : _scheduler(std::move(scheduler)), _image_provider(std::move(provider)), _desktop_updater(std::move(updater)) {
}

int Application::exec() {
    auto exec_func = [this]() {
        const auto image_data = _image_provider->get_image_data();
        _desktop_updater->update_background(image_data);
    };
    _scheduler->start(std::chrono::milliseconds(1000), exec_func);
    return 0;
}