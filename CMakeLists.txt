cmake_minimum_required(VERSION 3.6)

project(tryalgorithm)

enable_testing()

add_executable(bubble src/bubble.c)

add_test(NAME bubble COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/bubble)

add_executable(insert src/insertsort.c)

add_test(NAME insert COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/insert)

set(targetlist bubble insert)

install(TARGETS  ${targetlist}
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin  # 可执行文件安装路径
        )