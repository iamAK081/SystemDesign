cmake_minimum_required(VERSION 3.10)
project(SystemDesign)

set(CMAKE_CXX_STANDARD 17)

# Build executables for each .cpp file except test files
file(GLOB SRC_FILES "src/*.cpp")
foreach(source_file ${SRC_FILES})
    get_filename_component(source_name ${source_file} NAME_WE)
    if(NOT source_name MATCHES "_test$")
        add_executable(${source_name} ${source_file})
    endif()
endforeach()

# GoogleTest setup (manual install)
include_directories("C:/Arul/working/c++project/googletest/googletest/include")
link_directories("C:/Arul/working/c++project/googletest/build/lib") # Adjust if needed

enable_testing()

# Build and link test executables
file(GLOB TEST_FILES "src/*_test.cpp")
foreach(test_file ${TEST_FILES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file} src/ObserverPattern.cpp)
    target_link_libraries(${test_name} gtest gtest_main)
    add_test(NAME ${test_name} COMMAND ${test_name} --gtest_output=xml:${test_name}_junit.xml)
endforeach()