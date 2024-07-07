cmake_minimum_required(VERSION 3.14)
project(coding_corner VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

option(ENABLE_TESTING  "Enable a Unit Testing build."     ON)
if(ENABLE_TESTING)
  # Enables testing functionalities in CMake
  enable_testing()

  # Set a variable for test results directory (optional)
  set(XML_TEST_RESULTS_DIR "${CMAKE_BINARY_DIR}/test_results")

  # Declare GoogleTest as a fetchable content
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0 # specify the version you need
  )

  # Make the fetched content available for the project
  FetchContent_MakeAvailable(googletest)
endif()

# Set the library directory
add_subdirectory(libs/example_library)
add_subdirectory(libs/sdl_interface)

# Set the application directory
add_subdirectory(bin/example_application)
add_subdirectory(bin/simple_sdl_ui)
