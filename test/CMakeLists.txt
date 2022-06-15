project(DesktopChangeAgentTest)


set(src download_service_test.cpp)
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} GTest::gtest_main)
