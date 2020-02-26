cmake_minimum_required(VERSION 3.10)

# set the project name
project(cpwite VERSION 0.1 LANGUAGES CXX)

# add the executable
add_executable(cpwite src/main.cpp src/test/ytcf/ytcf-tasks.cpp)
