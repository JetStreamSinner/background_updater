set(src main.cpp curl_download_service.cpp gnome_update_service.cpp cli.cpp gnome_change_background_command.cpp)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} ${src})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})