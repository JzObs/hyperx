cmake_minimum_required(VERSION 3.20)

if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-W -Wall -Werror)
endif()

add_library(SDL2 INTERFACE)
target_include_directories(SDL2 INTERFACE include)
target_link_libraries(SDL2 INTERFACE mingw32)
target_link_libraries(SDL2 INTERFACE C:/Users/x/Documents/hyperx/sdl2/lib/libSDL2main.a)
target_link_libraries(SDL2 INTERFACE C:/Users/x/Documents/hyperx/sdl2/lib/libSDL2.dll.a)