#include "VertexArray.h"

VertexArray::VertexArray()
	: m_Id(0)
{
	glGenVertexArrays(1, &m_Id);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_Id);
}

void VertexArray::AddIndexedVertexBuffer(const VertexBuffer & vertexBuffer, const IndexBuffer & indexBuffer)
{
	Bind();

	vertexBuffer.Bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	indexBuffer.Bind();

	Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_Id);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}
