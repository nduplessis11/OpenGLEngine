#pragma once

#include <GL/glew.h>

#include "glm/glm.hpp"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh
{
private:
	VertexArray m_VertexArray;
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;
public:
	Mesh(const GLfloat* data, GLuint count, const GLuint* indices, GLuint indexCount);
	~Mesh();

	void SetDraw();
	void UnsetDraw();
};

