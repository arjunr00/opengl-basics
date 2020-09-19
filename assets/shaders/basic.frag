#version 330 core

in vec3 vertColor;
in vec2 texCoord;

out vec4 outColor;

uniform sampler2D tex;

void main() {
  outColor = texture(tex, texCoord);
}
