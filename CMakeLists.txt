CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

PROJECT(light)

FILE(GLOB sources src/*.cpp)
FILE(GLOB shaders src/shaders/*.frag src/shaders/*.vert)

ADD_DEFINITIONS(-DDEBUG)

ADD_EXECUTABLE(light ${sources})

TARGET_LINK_LIBRARIES(light glfw GL GLU Xrandr)
