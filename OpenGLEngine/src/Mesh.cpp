#include "Mesh.h"

Mesh::Mesh(const GLfloat* data, GLuint count, const GLuint* indices, GLuint indexCount)
	: m_VertexBuffer(data, count), m_IndexBuffer(indices, indexCount)
{
	m_VertexArray.AddIndexedVertexBuffer(m_VertexBuffer, m_IndexBuffer);
}

Mesh::~Mesh()
{
}

void Mesh::SetDraw()
{
	m_VertexArray.Bind();
}

void Mesh::UnsetDraw()
{
	m_VertexArray.Unbind();
}