#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
	GLuint m_Id;

public:
	VertexBuffer();
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
	void AddData(GLfloat * data, GLint count) const;
};

