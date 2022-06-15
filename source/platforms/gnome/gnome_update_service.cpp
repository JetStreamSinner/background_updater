#include "gnome_update_service.h"
#include "../../cli_terminal.h"
#include "../../utils.h"
#include "gnome_change_background_command.h"
#include <fstream>
#include <string_view>

void GnomeDesktopUpdateService::update_background(const std::string &image_data) const {
    // Its not very good approach, so its should be refactored later
    std::stringstream temp_dir_formatter;
    const std::filesystem::path temp_dir_name = "/background_updater";
    const std::filesystem::path os_temp_dir = std::filesystem::temp_directory_path();

    temp_dir_formatter << os_temp_dir.c_str() << temp_dir_name.c_str();
    const std::filesystem::path temp_path = temp_dir_formatter.str();
    create_temp_directory(temp_path);

    const std::filesystem::path filename = "/out.png";
    std::stringstream saving_path_formatter;
    saving_path_formatter << temp_path.c_str() << filename.c_str();
    const std::filesystem::path absolute_path = saving_path_formatter.str();

    std::fstream out(absolute_path, std::ios::out | std::ios::trunc);
    if (!out.is_open()) {
        throw std::runtime_error(error_formatter("Cannot open file ", absolute_path, " for saving"));
    }

    out.write(image_data.c_str(), image_data.size());
    out.close();
    if (out.bad()) {
        throw std::runtime_error(error_formatter("Cannot write data in ", absolute_path));
    }

    GnomeChangeBackgroundCommand command(absolute_path);
    CliTerminal terminal;
    terminal.execute(command);
}

void GnomeDesktopUpdateService::create_temp_directory(const std::filesystem::path& path) const {
    const bool path_exist = std::filesystem::exists(path);
    if (path_exist) {
        return;
    }
    std::filesystem::create_directory(path);
}