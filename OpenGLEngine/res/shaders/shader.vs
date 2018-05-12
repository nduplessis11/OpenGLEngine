#version 450

layout(location = 0)in vec3 position;
layout(location = 1)in vec4 in_color;
layout(location = 2)in vec2 in_texCoord;

out vec4 vertex_color;
out vec2 vertex_texCoord;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main() 
{
	gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0);
	vertex_color = in_color;
	vertex_texCoord = in_texCoord;
};
