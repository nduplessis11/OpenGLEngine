#include "Shader.h"

#include <fstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string vertexSource = LoadShaderFile(vertexPath);
	std::string fragmentSource = LoadShaderFile(fragmentPath);

	CreateProgram(vertexSource, fragmentSource);
}

Shader::~Shader()
{
	glDeleteProgram(m_Id);
}

std::string Shader::LoadShaderFile(const std::string& filepath)
{
	std::ifstream file;
	file.open(filepath.c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cout << "Unable to load shader file: " << filepath << std::endl;
	}

	return output;
}

void Shader::CreateProgram(const std::string& vertexSource, const std::string& fragmentSource)
{
	const char* vertexSourceStr = vertexSource.c_str();
	const char* fragmentSourceStr = fragmentSource.c_str();

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexSourceStr, nullptr);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentSourceStr, nullptr);
	glCompileShader(fs);

	m_Id = glCreateProgram();
	glAttachShader(m_Id, fs);
	glAttachShader(m_Id, vs);
	glLinkProgram(m_Id);

	glDeleteShader(fs);
	glDeleteShader(vs);
}

void Shader::Bind() const
{
	glUseProgram(m_Id);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}
