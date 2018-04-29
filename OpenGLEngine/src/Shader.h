#pragma once

#include <GL/glew.h>

class Shader
{
private:
	GLuint m_Id;
public:
	Shader();
	~Shader();

	void CreateProgram(const char * vertex_shader, const char * fragment_shader);
	void UseProgram() const;
};

