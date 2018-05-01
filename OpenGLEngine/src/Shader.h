#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
private:
	GLuint m_Id;
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	void CreateProgram(const std::string& vertexSource, const std::string& fragmentSource);
	void Bind() const;
	void Unbind() const;
private:
	std::string LoadShaderFile(const std::string& filepath);
};

