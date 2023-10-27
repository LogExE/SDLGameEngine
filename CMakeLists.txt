cmake_minimum_required(VERSION 3.10)

project("SDLMario")

file(GLOB MARIO_SRC
    "src/*.cpp"
    "src/interfaces/*.cpp"
)

include_directories("include")

add_executable(SDLMario ${MARIO_SRC})

target_compile_options(SDLMario PRIVATE -Wall -Wextra -Wpedantic)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/sdl2-cmake-modules/)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2_ttf REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::Main SDL2::Image SDL2::Net SDL2::TTF)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Anonymous.ttf DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/netset.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})