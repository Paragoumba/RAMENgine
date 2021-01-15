#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;

uniform float x;
uniform float y;

void main(){
    FragColor = texture(texture1, TexCoord);
}