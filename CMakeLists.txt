cmake_minimum_required (VERSION 2.8.12)

# add c++11 standard to compiler
add_compile_options(-std=c++11)

project(GESFML)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml")

include_directories(${SFML_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/GESFML)

file(GLOB_RECURSE SRC_FILES
    GLOB_CPP_PATTERNS src/*.cpp */GESFML/*.cpp
    GLOB_H_PATTERNS include*.h */GESFML/*.h RECURSE_GROUP
)

set(EXE_NAME "GESFML")
add_executable(${EXE_NAME} ${SRC_FILES})

# link with SFML library dependiences
target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml/include"
)
