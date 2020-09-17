#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer {
  public:
    Renderer(const char *windowName, int width, int height);
    ~Renderer();

    void render();

  private:
    GLFWwindow *window;

    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);

    void processInput();
};

#endif /* #ifndef RENDERER */
