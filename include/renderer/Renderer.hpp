#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <renderer/Mesh.hpp>

class Renderer {
  public:
    Renderer(std::string windowName, int width, int height);
    ~Renderer();

    void render(std::vector<Mesh *> &meshes);

  private:
    GLFWwindow *window;

    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);

    void processInput();
};

#endif /* #ifndef RENDERER */
