cmake_minimum_required(VERSION 3.18)
project(DesktopChangeAgent)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(source)

enable_testing()
add_subdirectory(test)