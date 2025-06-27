cmake_minimum_required(VERSION 3.30)
project(test_modern_c)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(cmocka REQUIRED)

add_executable(test_modern_c test.c)
target_include_directories(test_modern_c PRIVATE ${CMAKE_SOURCE_DIR}/include /usr/local/include/safeclib)
target_link_libraries(test_modern_c PRIVATE cmocka)