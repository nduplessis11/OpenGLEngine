#include "Shader.h"

#include <fstream>
#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::string vertexSource = LoadShaderFile(vertexPath);
	std::string fragmentSource = LoadShaderFile(fragmentPath);

	CreateProgram(vertexSource, fragmentSource);
	
	Bind();
	m_Model_s = glGetUniformLocation(m_Id, "u_Model");
	m_View_s = glGetUniformLocation(m_Id, "u_View");
	m_Projection_s = glGetUniformLocation(m_Id, "u_Projection");
	Unbind();
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

void Shader::SetModel(const glm::mat4 & model) const
{
	glUniformMatrix4fv(m_Model_s, 1, GL_FALSE, &model[0][0]);
}

void Shader::SetView(const glm::mat4& view) const
{
	glUniformMatrix4fv(m_View_s, 1, GL_FALSE, &view[0][0]);
}

void Shader::SetProjection(const glm::mat4& projection) const
{
	glUniformMatrix4fv(m_Projection_s, 1, GL_FALSE, &projection[0][0]);
}

void Shader::SetAmbientLight(const glm::vec3 & light) const
{
	GLuint ambientLight_s = glGetUniformLocation(m_Id, "u_AmbientLight");
	glUniform3fv(ambientLight_s, 1, glm::value_ptr(light));
}
