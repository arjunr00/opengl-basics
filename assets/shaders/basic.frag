#version 330 core

in vec3 vertColor;
in vec2 texCoord;

out vec4 outColor;

uniform sampler2D tex0;
uniform sampler2D tex1;

void main() {
  outColor = mix(texture(tex0, texCoord), texture(tex1, texCoord), 0.3) * vec4(vertColor, 1.0);
}
