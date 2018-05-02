#pragma once

#include <GL/glew.h>

#include "VertexBuffer.h"

class VertexArray
{
private:
	GLuint m_Id;

public:
	VertexArray();
	~VertexArray();

	void AddVertexBuffer(const VertexBuffer & buffer);
	void Bind() const;
	void Unbind() const;
};

