cmake_minimum_required(VERSION 3.30)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(nana)

add_executable(untitled1 main.cpp
        src/main_form.cpp
        src/set_1_form.cpp)

target_link_libraries(untitled1 nana)
target_include_directories(untitled1 PRIVATE api)