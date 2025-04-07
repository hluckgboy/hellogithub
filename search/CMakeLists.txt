cmake_minimum_required(VERSION 3.6)

project(search)

enable_testing()

add_executable(binary-search ${CMAKE_CURRENT_SOURCE_DIR}/src/binary-search.c)
add_test(NAME binary-search COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/binary-search)

install(TARGETS binary-search RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_custom_target(clean_all
    COMMAND $(CMAKE_COMMAND) -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMENT "remove binary directory."
)