cmake_minimum_required(VERSION 3.22)
project(first_project)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include_directories(include)

add_library(ipb_arithmetic 
    src/subtract.cpp 
    src/sum.cpp
)


set(SOURCE_FILES
    src/main.cpp
)
# Create an executable target for your main.cpp
add_executable(main ${SOURCE_FILES})

# Link the ipb_arithmetic library to the main executable
target_link_libraries(main ipb_arithmetic)
# Specify the installation directory for headers and library
set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install)

# Specify the installation locations for headers and library
install(TARGETS main DESTINATION ${INSTALL_DIR}/lib)
install(DIRECTORY include/ DESTINATION ${INSTALL_DIR}/include)

