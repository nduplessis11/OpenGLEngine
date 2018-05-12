#version 450

in vec4 vertex_color;
in vec2 vertex_texCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main() 
{
	//color = vertex_color;
	color = texture(ourTexture, vertex_texCoord) * vertex_color;
};