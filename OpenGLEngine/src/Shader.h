#pragma once

#include <GL/glew.h>
#include <string>

#include "glm/glm.hpp"

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

	void SetModel(const glm::mat4& model) const;
	void SetView(const glm::mat4& view) const;
	void SetProjection(const glm::mat4& projection) const;

	void SetAmbientLight(const glm::vec3 & light) const;
private:
	std::string LoadShaderFile(const std::string& filepath);
	void CreateProgram(const std::string& vertexSource, const std::string& fragmentSource);
};

