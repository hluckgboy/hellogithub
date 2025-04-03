cmake_minimum_required(VERSION 3.6)

project(ioprogram)

set(targetlist epoll poll select)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_executable(epoll ${CMAKE_CURRENT_SOURCE_DIR}/src/epoll.c)
add_test(NAME epoll COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/epoll)

add_executable(poll ${CMAKE_CURRENT_SOURCE_DIR}/src/poll.c)
add_test(NAME poll COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/poll)

add_executable(select ${CMAKE_CURRENT_SOURCE_DIR}/src/select.c)
add_test(NAME select COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/select)

install(TARGETS ${targetlist}
    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

add_custom_target(clean_all
    COMMAND $(CMAKE_COMMAND) -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMENT "Cleaning all executables."  
)
