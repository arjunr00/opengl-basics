#version 330 core

out vec4 outColor;

uniform vec4 uniformColor;

void main() {
  outColor = uniformColor;
}
