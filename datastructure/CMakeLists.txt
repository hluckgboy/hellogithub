cmake_minimum_required(VERSION 3.6)

project(datastruct)

#aux_source_directory(./ SRCDIR)

enable_testing()

add_executable(array ${CMAKE_CURRENT_SOURCE_DIR}/src/array.c)
add_test(NAME array COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/array)

add_executable(list ${CMAKE_CURRENT_SOURCE_DIR}/src/list.c)
add_test(NAME list COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/list)

add_executable(stack ${CMAKE_CURRENT_SOURCE_DIR}/src/stack.c)
add_test(NAME stack COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/stack)

set(targetlist array list stack)

install(TARGETS ${targetlist}
    RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin #可执行文件安装路径
)

add_custom_target(clean_all
    COMMAND $(CMAKE_COMMAND) -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMENT "Cleaning all executables"  
)