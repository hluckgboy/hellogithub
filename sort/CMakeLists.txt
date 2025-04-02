cmake_minimum_required(VERSION 3.6)

project(tryalgorithm)

enable_testing()

add_executable(bubble ${CMAKE_CURRENT_SOURCE_DIR}/src/bubble.c)
add_test(NAME bubble COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/bubble)

add_executable(insert ${CMAKE_CURRENT_SOURCE_DIR}/src/insertsort.c)
add_test(NAME insert COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/insert)

add_executable(select ${CMAKE_CURRENT_SOURCE_DIR}/src/select.c)
add_test(NAME select COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/select)

add_executable(quick ${CMAKE_CURRENT_SOURCE_DIR}/src/quick.c)
add_test(NAME quick COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/quick)

add_executable(merge ${CMAKE_CURRENT_SOURCE_DIR}/src/merge.c)
add_test(NAME merge COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/merge)

set(targetlist bubble insert select quick merge)

install(TARGETS  ${targetlist}
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin  # 可执行文件安装路径
        )

add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMENT "Cleaning all generated binaries and libraries"
)