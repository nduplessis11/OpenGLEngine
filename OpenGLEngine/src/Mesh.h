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

	GLenum m_DrawMode;
	GLuint m_IndexCount;
public:
	Mesh(const GLfloat* data, GLuint count, const GLuint* indices, GLuint indexCount, GLenum mode);
	~Mesh();

	void SetDraw();
	void UnsetDraw();

	inline GLenum GetDrawMode() const { return m_DrawMode; }
	inline GLuint GetIndexCount() const { return m_IndexCount; }
};

