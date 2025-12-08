cmake_minimum_required(VERSION 3.15)

add_subdirectory(vendor/SDL)

project(GeneticSimulation CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
)

add_executable(GeneticSimulation ${SOURCES})


if(MSVC)
    target_compile_options(GeneticSimulation PRIVATE /W4)
else()
    target_compile_options(GeneticSimulation PRIVATE -Wall -Wextra) #ligne 20
endif()