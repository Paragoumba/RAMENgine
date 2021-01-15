#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D texture1;
uniform int hasTexture;
uniform vec3 color;

void main(){
    if (hasTexture == 1){
        FragColor = texture(texture1, TexCoord);
    } else {
        FragColor = vec4(color, 1.0);
    }
}