cmake_minimum_required(VERSION 3.10)

project(opengl-basics VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(SOURCES
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/renderer/Renderer.cpp
  ${PROJECT_SOURCE_DIR}/src/renderer/Mesh.cpp
  ${PROJECT_SOURCE_DIR}/src/renderer/Shader.cpp
  ${PROJECT_SOURCE_DIR}/src/renderer/Texture.cpp)

set(HEADERS
  ${PROJECT_SOURCE_DIR}/include/renderer/Renderer.hpp
  ${PROJECT_SOURCE_DIR}/include/renderer/Mesh.hpp
  ${PROJECT_SOURCE_DIR}/include/renderer/Shader.hpp
  ${PROJECT_SOURCE_DIR}/include/renderer/Texture.hpp)

find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

if (WIN32)
  set(LIBS glfw opengl32)
elseif(UNIX AND NOT APPLE)
  set(OpenGL_GL_PREFERENCE "GLVND")
  find_package(OpenGL REQUIRED)
  add_definitions(${OPENGL_DEFINITIONS})
  find_package(X11 REQUIRED)
  set(LIBS glfw X11 Xrandr Xi GL dl)
  set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")
elseif(APPLE)
  # TODO
else()
  set(LIBS )
endif(WIN32)

add_library(GLAD ${PROJECT_SOURCE_DIR}/src/lib/glad.c)
add_library(STB_IMAGE ${PROJECT_SOURCE_DIR}/src/lib/stb_image.c)

set(LIBS ${LIBS} GLAD STB_IMAGE)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

include_directories(
  ${PROJECT_SOURCE_DIR}/src/
  ${PROJECT_SOURCE_DIR}/include/
)
