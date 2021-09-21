cmake_minimum_required(VERSION 3.17)
project(taskmanager)

set(CMAKE_CXX_STANDARD 14)


set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
find_package(Qt5Widgets REQUIRED)

add_executable(taskmanager main.cpp Service.cpp Service.h Task.cpp Task.h Repository.cpp Repository.h GUI.cpp GUI.h)

target_link_libraries(taskmanager Qt5::Widgets)