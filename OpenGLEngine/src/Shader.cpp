#include "Shader.h"

Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::CreateProgram(const char * vertex_shader, const char * fragment_shader)
{
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, nullptr);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, nullptr);
	glCompileShader(fs);

	m_Id = glCreateProgram();
	glAttachShader(m_Id, fs);
	glAttachShader(m_Id, vs);
	glLinkProgram(m_Id);
}

void Shader::UseProgram() const
{
	glUseProgram(m_Id);
}
