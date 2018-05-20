#version 450

out vec4 color;

uniform vec3 u_AmbientLight;

void main()
{
	color = vec4(u_AmbientLight, 1.0);
};