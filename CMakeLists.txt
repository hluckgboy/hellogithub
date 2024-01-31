cmake_minimum_required(VERSION 3.6)

project(tryalgorithm)

enable_testing()

add_executable(bubble src/bubble.c)

add_test(NAME bubble COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/bubble)

install(TARGETS bubble
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin  # 可执行文件安装路径
        )