#version 400

in vec3 vp;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main() 
{
	gl_Position = u_Projection * u_View * u_Model * vec4(vp, 1.0);
};
