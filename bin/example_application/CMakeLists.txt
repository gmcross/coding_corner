set(executable_name example_application)
set(SOURCES src/example_application_main.cpp)

add_executable(${executable_name} ${SOURCES})
target_link_libraries(${executable_name} PRIVATE coding_corner::example_library)
