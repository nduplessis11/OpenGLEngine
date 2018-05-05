#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
private:
	GLuint m_Id;
	GLuint m_Model_s;
	GLuint m_View_s;
	GLuint m_Projection_s;
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void Bind() const;
	void Unbind() const;
private:
	std::string LoadShaderFile(const std::string& filepath);
	void CreateProgram(const std::string& vertexSource, const std::string& fragmentSource);
};

