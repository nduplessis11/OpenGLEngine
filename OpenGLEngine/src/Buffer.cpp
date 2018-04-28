#include "Buffer.h"


Buffer::Buffer()
	: m_Id(0)
{
	glGenBuffers(1, &m_Id);
}


Buffer::~Buffer()
{
}

void Buffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void Buffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::AddData(GLfloat * data, GLint count)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
	Unbind();
}
