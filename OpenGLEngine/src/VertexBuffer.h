#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
	GLuint m_Id;

public:
	VertexBuffer(const GLfloat * data, GLint count);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

