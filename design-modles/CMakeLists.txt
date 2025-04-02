cmake_minimum_required(VERSION 3.6)

project(design)

enable_testing()

add_executable(simple-factory ${CMAKE_CURRENT_SOURCE_DIR}/src/simple-factory.c)
add_test(NAME simple-factory COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/simple-factory)

install(TARGETS simple-factory
    RUNTIME
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

add_custom_target(clean_all
    COMMAND $(CMAKE_COMMAND) -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMENT "Cleaning all executables"  
)