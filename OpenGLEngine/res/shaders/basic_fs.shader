#version 450

in vec2 vertex_texCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main() 
{
	color = texture(ourTexture, vertex_texCoord);
};