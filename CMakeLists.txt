cmake_minimum_required(VERSION 2.6.0)

# add c++11
add_compile_options(-std=c++11)

project(GameEngine)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES
    GLOB_CPP_PATTERNS src/*.cpp
    GLOB_H_PATTERNS include*.h RECURSE_GROUP
)

set(EXE_NAME "GameEngine")
add_executable(${EXE_NAME} ${SRC_FILES})

#SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_DIR}/include)
    target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
endif()
    