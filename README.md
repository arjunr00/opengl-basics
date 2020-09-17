# OpenGL Tutorial

After I gave up on trying to get NVIDIA drivers to work with my Ubuntu installation, I decided to try out OpenGL instead.
I'm using [this highly recommended tutorial](https://learnopengl.com/).

## How to build

Make sure [GLFW](https://www.glfw.org/) and [GLM](https://glm.g-truc.net/0.9.9/index.html) are installed.
Then, run `make` to generate the executable.
Run `make clean` to remove all generated files.

## Notes

* I used [GLAD](https://github.com/Dav1dde/glad) to generate `include/glad/glad.h`, `include/KHR/khrplatform.h`, and `src/glad.c`.
