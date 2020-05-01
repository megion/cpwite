cmake_minimum_required(VERSION 3.10)

# set the project name
project(cpwite VERSION 0.1 LANGUAGES CXX)

# add the executable
add_executable(cpwite src/main.cpp src/test/week1/week1-tasks.cpp
    src/test/week2/week2-tasks.cpp src/test/week2/bus-stop.cpp)
