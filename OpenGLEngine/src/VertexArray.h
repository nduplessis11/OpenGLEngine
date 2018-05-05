#pragma once

#include <GL/glew.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

class VertexArray
{
private:
	GLuint m_Id;
public:
	VertexArray();
	~VertexArray();

	void AddIndexedVertexBuffer(const VertexBuffer & vertexBuffer, const IndexBuffer & indexBuffer);
	void Bind() const;
	void Unbind() const;
};

