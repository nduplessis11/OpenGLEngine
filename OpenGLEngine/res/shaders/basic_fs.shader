#version 450

in vec2 vertex_texCoord;

out vec4 color;

uniform sampler2D u_Texture;
uniform vec3 u_AmbientLight;

void main() 
{
	color = texture(u_Texture, vertex_texCoord) * vec4(u_AmbientLight, 1.0);
};