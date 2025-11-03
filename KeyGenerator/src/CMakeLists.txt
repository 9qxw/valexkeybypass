cmake_minimum_required(VERSION 3.15)
project(KeyGenerator)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(OPENGL REQUIRED gl)
pkg_check_modules(CURL REQUIRED libcurl)

find_path(IMGUI_INCLUDE_DIRS imgui.h PATH_SUFFIXES imgui)
find_library(IMGUI_LIBRARIES NAMES imgui)

add_executable(KeyGenerator
    src/main.cpp
    src/ui/WindowManager.cpp
    src/ui/ComponentBuilder.cpp
    src/ui/TabController.hpp
    src/api/ExternalEndpoint.cpp
    src/api/ExecutorEndpoint.hpp
    src/core/NetworkOperations.hpp
    src/core/DataProcessing.hpp
)

target_include_directories(KeyGenerator PRIVATE 
    ${IMGUI_INCLUDE_DIRS}
    include/
)

target_link_libraries(KeyGenerator 
    ${GLFW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${CURL_LIBRARIES}
    ${IMGUI_LIBRARIES}
)

target_compile_options(KeyGenerator PRIVATE 
    -Wall -Wextra -O2
)