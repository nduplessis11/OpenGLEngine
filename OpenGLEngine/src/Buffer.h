#pragma once

#include <GL/glew.h>

class Buffer
{
private:
	GLuint m_Id;

public:
	Buffer();
	~Buffer();

	void Bind();
	void Unbind();
	void AddData(GLfloat * data, GLint count);
};

