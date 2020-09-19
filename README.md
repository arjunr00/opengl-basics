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
Open the CMake GUI.
Set the source directory to the root of this repository and set the build directory to a new sub-directory called `build` (or anything you want), then click Configure and follow the steps (I use [vcpkg](https://github.com/microsoft/vcpkg) so I specify its CMake toolchain).
Once that's done click Generate.
Inside the `build` folder will be a file name `opengl-basics.sln`.
Open this in Visual Studio.
Once everything is loaded, click **Build** > **Build 'opengl-basics'** or press Ctrl-B.
An executable name `opengl-basics.exe` will be generated inside `build/Debug/`.

## How to run

**Ubuntu:**
After building, make sure you're at the root of the repository, then type `./build/opengl-basics`.

**Windows:**
Make a new folder inside `build/Debug` named `src`, then copy the `shaders/` folder from `src` (in the root of the repository) to the aforementioned new folder.
Then, just run `opengl-basics.exe` from `build/Debug`.

(NOTE: these are because right now shader files are opened relative to the directory the executable is run from. In the future, I'll have the user supply a shader directory when running the program so that it's more portable.)

## How to use

Press 1 to switch to filled mode and 2 to switch to wireframe mode. Press Q to close the application.

## What it looks like
![opengl-rect](https://user-images.githubusercontent.com/30734384/93632268-0ec1bd80-f9bb-11ea-8b75-ec928ca7a7fa.gif)

## Notes

* I used [GLAD](https://github.com/Dav1dde/glad) to generate `include/glad/glad.h`, `include/KHR/khrplatform.h`, and `src/glad.c`.
* CMakeLists.txt based off of [this one](https://github.com/JoeyDeVries/LearnOpenGL/blob/master/CMakeLists.txt) until I can properly learn CMake better.
