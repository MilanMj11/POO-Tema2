cmake_minimum_required(VERSION 3.15)

# NOTE: update executable name in .github/workflows/cmake.yml:44 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp Vehicle.h Vehicle.cpp Depot.h Depot.cpp Tank.h Tank.cpp Humvee.h Humvee.cpp Exception.h Exception.cpp GenerareID.h GenerareID.cpp)

