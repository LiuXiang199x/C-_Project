project(file_operation)

cmake_minimum_required(VERSION 3.10)

include_directories(include)

add_executable(test src/main.cc)

set(EXECUTABLE_OUTPUT_PATH bin)