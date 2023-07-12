cmake_minimum_required(VERSION 3.22)
project(hw_3)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    src/main.cpp
)

include_directories(include)
add_library(html_api
    src/html_writer.cpp
    src/image_browser.cpp
)

add_executable(create_image_browser ${SOURCE_FILES})

find_package(fmt REQUIRED)
target_link_libraries(create_image_browser fmt html_api)


install(TARGETS create_image_browser DESTINATION ${CMAKE_INSTALL_PREFIX})