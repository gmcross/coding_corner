set(executable_name simple_sdl_ui)
set(SOURCES src/simple_sdl_ui_main.cpp)

add_executable(${executable_name} ${SOURCES})
target_link_libraries(${executable_name} PRIVATE coding_corner::sdl_interface)
