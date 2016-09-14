cmake_minimum_required(VERSION 3.3)
project(texture_mapping)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TextureMapper.cpp TextureMapper.h Vertex.h)

add_executable(texture_mapping ${SOURCE_FILES})
target_link_libraries(texture_mapping libfreeglut.a libfreeglut_static.a)