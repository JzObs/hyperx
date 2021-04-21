cmake_minimum_required(VERSION 3.20)

if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-W -Wall -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)

project(hyperx)

add_subdirectory(sdl2)
add_subdirectory(logger)

add_executable(hyperx hyperx.cpp Initializer.cpp Window.cpp Renderer.cpp Object.cpp Warehouse.cpp App.cpp Scene.cpp Texture.cpp)
target_link_libraries(hyperx SDL2 utility_logger)

configure_file(SDL2.dll SDL2.dll COPYONLY)
configure_file(SDL2_image.dll SDL2_image.dll COPYONLY)
configure_file(libjpeg-9.dll libjpeg-9.dll COPYONLY)
configure_file(zlib1.dll zlib1.dll COPYONLY)
configure_file(libpng16-16.dll libpng16-16.dll COPYONLY)