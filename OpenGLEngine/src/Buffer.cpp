#include "Buffer.h"


Buffer::Buffer()
	: m_Id(0)
{
	glGenBuffers(1, &m_Id);
}


Buffer::~Buffer()
{
	glDeleteBuffers(1, &m_Id);
}

void Buffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void Buffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::AddData(GLfloat * data, GLint count) const
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	Unbind();
}
