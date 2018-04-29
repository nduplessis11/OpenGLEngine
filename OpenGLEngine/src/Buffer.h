#pragma once

#include <GL/glew.h>

class Buffer
{
private:
	GLuint m_Id;

public:
	Buffer();
	~Buffer();

	void Bind() const;
	void Unbind() const;
	void AddData(GLfloat * data, GLint count) const;
};

