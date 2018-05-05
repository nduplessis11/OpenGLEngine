#pragma once

#include <GL/glew.h>

#include "VertexArray.h"
#include "VertexBuffer.h"

class Mesh
{
private:
	VertexArray m_VertexArray;
	VertexBuffer m_VertexBuffer;
public:
	Mesh(const GLfloat* data, GLuint count);
	~Mesh();

	void SetDraw();
	void UnsetDraw();
};

