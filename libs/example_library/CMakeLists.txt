set(library_name example_library)

set(SOURCES
    src/example_library_source.cpp
)

add_library(${library_name} SHARED ${SOURCES})
add_library(${PROJECT_NAME}::${library_name} ALIAS ${library_name})

target_include_directories(${library_name}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# uncomment to link to external libraries
# target_link_libraries(${library_name}
#     PUBLIC
#         ${PROJECT_NAME}::example_interface
# )

# install directory
install(DIRECTORY include/${library_name} DESTINATION include COMPONENT dev)

# install library
install(TARGETS ${library_name}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# install cmake config
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)
