#version 330 core

in vec3 vertColor;

out vec4 outColor;

uniform float multiplier;

void main() {
  outColor = vec4(vertColor * multiplier, 1.0);
}
