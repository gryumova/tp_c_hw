cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "--coverage -Wall -Werror -Wpedantic")

include_directories(project/include)
include_directories(project/include/test/include)

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)


enable_testing()
add_subdirectory(project/test)

add_library(one_process STATIC ${PROJECT_SOURCE_DIR}/project/src/sum.c 
${PROJECT_SOURCE_DIR}/project/src/make.c)

add_library(multi_process SHARED ${PROJECT_SOURCE_DIR}/project/src/sum_par.c 
${PROJECT_SOURCE_DIR}/project/src/make.c)

add_executable(prog_lin ${PROJECT_SOURCE_DIR}/project/src/main.c)
target_link_libraries(prog_lin one_process)

add_executable(prog_par ${PROJECT_SOURCE_DIR}/project/src/main.c)
target_link_libraries(prog_par multi_process)

add_executable(gen_file ${PROJECT_SOURCE_DIR}/project/src/gen.c)