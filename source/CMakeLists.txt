set(src main.cpp web_image_provider.cpp platforms/gnome/gnome_updater.cpp cli_terminal.cpp platforms/gnome/gnome_change_background_command.cpp
        scheduler.cpp bytes_array.cpp image_resolver.cpp image.cpp application.cpp)


add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})