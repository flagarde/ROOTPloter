cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(ROOTPlotter LANGUAGES CXX)

option(USE_SPDLOG "Use spdlog" ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

add_subdirectory(src)

add_subdirectory(examples)

include(CTest)
add_subdirectory(tests)