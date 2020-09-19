# OpenGL Basics

After I gave up on trying to get NVIDIA drivers to work with my Ubuntu installation so I could develop with Vulkan, I decided to try out OpenGL instead.
I'm loosely following [this highly recommended tutorial](https://learnopengl.com/) to learn how the OpenGL API works with some organizational and operational changes of my own (such as using classes to encapsulate different aspects of drawing, like compiling shaders, drawing a shape, and the actual rendering).

## Dependencies

* [GLFW 3](https://www.glfw.org/)
* [GLM](https://glm.g-truc.net/0.9.9/index.html)
* [CMake](https://cmake.org/) 3.10 or higher

## How to build

**Ubuntu:**
Enter the following commands in a shell at the root of this repository:
```bash
$ cmake -B build .
$ make -C build
```

Or, you can do:
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

**Windows:**
_TODO_

## How to run

**Ubuntu:**
After building, make sure you're at the root of the repository, then type `./build/opengl-basics`.

**Windows:**
_TODO_

## How to use

Press 1 to switch to filled mode and 2 to switch to wireframe mode. Press Q to close the application.

## What it looks like
![opengl-rect](https://user-images.githubusercontent.com/30734384/93632268-0ec1bd80-f9bb-11ea-8b75-ec928ca7a7fa.gif)

## Notes

* I used [GLAD](https://github.com/Dav1dde/glad) to generate `include/glad/glad.h`, `include/KHR/khrplatform.h`, and `src/glad.c`.
* CMakeLists.txt based off of [this one](https://github.com/JoeyDeVries/LearnOpenGL/blob/master/CMakeLists.txt) until I can properly learn CMake better.
