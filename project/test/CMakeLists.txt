set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage --coverage -DBUILD_SHARED_LIBS=ON")
set(CMAKE_CXX_STANDARD 17)
include_directories("${PROJECT_SOURCE_DIR}/project/include")

file(GLOB tests "${PROJECT_SOURCE_DIR}/project/test/*.cpp")
list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/project/test/main.cpp")

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests"
    ${sources}
    ${file}
    "${PROJECT_SOURCE_DIR}/project/test/main.cpp")
  target_link_libraries("${name}_tests" gtest_main one_process multi_process)
  add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()