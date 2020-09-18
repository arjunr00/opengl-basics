# OpenGL Basics

After I gave up on trying to get NVIDIA drivers to work with my Ubuntu installation so I could develop with Vulkan, I decided to try out OpenGL instead.
I'm loosely following [this highly recommended tutorial](https://learnopengl.com/) to learn how the OpenGL API works with some organizational and operational changes of my own (such as using classes to encapsulate different aspects of drawing, like compiling shaders, drawing a shape, and the actual rendering).

## How to build

Make sure [GLFW](https://www.glfw.org/) and [GLM](https://glm.g-truc.net/0.9.9/index.html) are installed.
Then, run `make` to generate the executable.
Run `make clean` to remove all generated files.

## What it looks like
![Screenshot_20200917_225548](https://user-images.githubusercontent.com/30734384/93550307-1fc9ea80-f939-11ea-9d5e-9f428f3cf13b.png)

## Notes

* I used [GLAD](https://github.com/Dav1dde/glad) to generate `include/glad/glad.h`, `include/KHR/khrplatform.h`, and `src/glad.c`.
