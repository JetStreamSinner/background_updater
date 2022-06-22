#pragma once

#include <memory>
class ImageProvider;
class DesktopUpdater;
class IScheduler;

class Application {
public:
    explicit Application(std::unique_ptr<IScheduler>& scheduler, std::unique_ptr<ImageProvider> &provider, std::unique_ptr<DesktopUpdater> &updater);
    int exec();
private:
    std::unique_ptr<IScheduler> _scheduler;
    std::unique_ptr<ImageProvider> _image_provider;
    std::unique_ptr<DesktopUpdater> _desktop_updater;
};