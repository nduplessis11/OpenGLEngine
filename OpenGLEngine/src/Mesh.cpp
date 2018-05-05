#include "Mesh.h"

Mesh::Mesh(const GLfloat* data, GLuint count)
{
	m_VertexBuffer.AddData(data, count);
	m_VertexArray.AddVertexBuffer(m_VertexBuffer);
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