#version 450

out vec4 color;

uniform vec3 u_ObjectColor;
uniform vec3 u_LightColor;

void main()
{
	color = vec4(u_LightColor * u_ObjectColor, 1.0);
};