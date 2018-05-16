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

void VertexArray::AddIndexedVertexBuffer(const VertexBuffer & vertexBuffer, const IndexBuffer & indexBuffer, const VertexLayout & vertexLayout)
{
	Bind();

	vertexBuffer.Bind();

	std::vector<VertexAttribute>::const_iterator it;
	for (it = vertexLayout.attributes.begin(); it != vertexLayout.attributes.end(); it++)
	{
		glEnableVertexAttribArray(it->location);
		glVertexAttribPointer(it->location, it->dimensionCount, GL_FLOAT, GL_FALSE, vertexLayout.stride, (void*)it->offset);
	}

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
