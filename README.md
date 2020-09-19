# OpenGL Basics

After I gave up on trying to get NVIDIA drivers to work with my Ubuntu installation so I could develop with Vulkan, I decided to try out OpenGL instead.
I'm loosely following [this highly recommended tutorial](https://learnopengl.com/) to learn how the OpenGL API works with some organizational and operational changes of my own (such as using classes to encapsulate different aspects of drawing, like compiling shaders, drawing a shape, and the actual rendering).

## Dependencies

* [GLFW 3](https://www.glfw.org/)
* [GLM](https://glm.g-truc.net/0.9.9/index.html)
* [CMake](https://cmake.org/) 3.10 or higher

## How to build

**Ubuntu:**
Enter the following commands in a shell at the root of this repository (replacing `build` with whatever directory name you want):
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

This will generate a binary named `opengl-basics` inside the `build` folder.

**Windows:**
1. Open the CMake GUI.
2. Set the source directory to the root of this repository and set the build directory to a new sub-directory called `build` (or anything you want)
3. Click Configure and follow the steps (I use [vcpkg](https://github.com/microsoft/vcpkg) so I specify its CMake toolchain).
4. Once that's done, click Generate.
5. Inside the `build` folder will be a file name `opengl-basics.sln`.
Open this in Visual Studio.
6. Once everything is loaded, click **Build** > **Build 'opengl-basics'** or press Ctrl-B.
An executable name `opengl-basics.exe` will be generated inside `build/Debug/`.

## How to run

**Ubuntu:**
After building, make sure you're at the root of the repository, then type `./build/opengl-basics` in a shell.

**Windows:**
After building, make sure you're at the root of the repository, then type `./build/Debug/opengl-basics.exe` in a shell.

Alternatively, copy the `assets/` folder from the root of the repository to `build/Debug`.
Then, just run `opengl-basics.exe` from inside `build/Debug`.

## How to use

Press 1 to switch to filled mode and 2 to switch to wireframe mode. Press Q to close the application.

## What it looks like
![opengl-basics-img](https://user-images.githubusercontent.com/30734384/93688430-db9f2d00-fa93-11ea-86c8-bbebe2571dfc.gif)


## Notes

* I used [GLAD](https://github.com/Dav1dde/glad) to generate `include/glad/glad.h`, `include/KHR/khrplatform.h`, and `src/glad.c`.
* CMakeLists.txt based off of [this one](https://github.com/JoeyDeVries/LearnOpenGL/blob/master/CMakeLists.txt) until I can properly learn CMake better.
