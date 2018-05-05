#pragma once

#include <GL/glew.h>

class IndexBuffer
{
private:
	GLuint m_Id;
public:
	IndexBuffer(const GLuint* indices, GLuint count);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
};

