cmake_minimum_required(VERSION 3.30)

project(modern_c)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)


set(SOURCES
    modern_c.c
)

add_executable(modern_c ${SOURCES})
target_include_directories(modern_c PRIVATE ${CMAKE_SOURCE_DIR}/include /usr/local/include/safeclib)
target_link_libraries(modern_c PRIVATE safec)

