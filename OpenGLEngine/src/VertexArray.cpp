#include "VertexArray.h"

VertexArray::VertexArray()
	: m_Id(0)
{
	glGenVertexArrays(1, &m_Id);
}

VertexArray::~VertexArray()
{
}

void VertexArray::Bind()
{
	glBindVertexArray(m_Id);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}
