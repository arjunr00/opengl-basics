#version 330 core

layout (location = 0) in vec3 position;

out vec4 vertexColor;

void main() {
  gl_Position = vec4(position, 1.0);
  // Adjust components to get vertex colors between 0 and 1
  vertexColor = vec4((position + 1.0) * 0.5, 1.0);
}
