#pragma once

#include <GL/glew.h>

class VertexArray
{
private:
	GLuint m_Id;

public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;
};

