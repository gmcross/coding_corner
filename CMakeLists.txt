cmake_minimum_required(VERSION 3.10)
project(coding_corner VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the library directory
add_subdirectory(libs/example_library)

# Set the application directory
add_subdirectory(bin/example_application)
