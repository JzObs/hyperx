cmake_minimum_required(VERSION 3.20)

if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-W -Wall -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)

project(hyperx)

add_subdirectory(sdl2)
find_library(SDL2_LIB SDL2)
add_executable(hyperx hyperx.cpp Initializer.cpp Window.cpp Renderer.cpp Object.cpp)
target_link_libraries(hyperx SDL2)

if(MSVC)
    configure_file(SDL2.dll SDL2.dll COPYONLY)
endif()