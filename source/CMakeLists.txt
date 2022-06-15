set(src main.cpp curl_download_service.cpp platforms/gnome/gnome_update_service.cpp cli_terminal.cpp platforms/gnome/gnome_change_background_command.cpp
        scheduler.cpp)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})