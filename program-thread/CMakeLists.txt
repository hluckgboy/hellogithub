cmake_minimum_required(VERSION 3.6)

project(program-thread)

set(targetlist program-pool thread-pool)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) # 添加头文件目录

enable_testing()

add_executable(program-pool ${CMAKE_CURRENT_SOURCE_DIR}/src/program-pool.c)
target_link_libraries(program-pool pthread) # 链接 pthread 库
add_test(NAME program-pool COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/program-pool)

add_executable(thread-pool ${CMAKE_CURRENT_SOURCE_DIR}/src/thread-pool.c)
target_link_libraries(thread-pool pthread) # 链接 pthread 库
add_test(NAME thread-pool COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/thread-pool)

install(TARGETS ${targetlist} 
        RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin        
)

add_custom_target(clean_all
    COMMAND $(CMAKE_COMMAND) -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMENT "Cleaning all executables."  
)