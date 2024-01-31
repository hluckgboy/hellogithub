cmake_minimum_required(VERSION 3.6)

project(tryalgorithm)

enable_testing()

add_executable(bubble src/bubble.c)
add_test(NAME bubble COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/bubble)

add_executable(insert src/insertsort.c)
add_test(NAME insert COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/insert)

add_executable(select src/select.c)
add_test(NAME select COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/select)

add_executable(quick src/quick.c)
add_test(NAME quick COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/quick)

set(targetlist bubble insert select quick)

install(TARGETS  ${targetlist}
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin  # 可执行文件安装路径
        )