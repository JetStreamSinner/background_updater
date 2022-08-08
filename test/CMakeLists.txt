project(DesktopChangeAgentTest)


set(src bytes_test.cpp ../source/bytes_array.cpp)
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
