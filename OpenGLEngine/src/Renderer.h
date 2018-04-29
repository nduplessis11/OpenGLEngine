#pragma once

#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

#include <GL/glew.h>

class Renderer
{
private:
	const VertexArray * m_Va;
	const Buffer * m_Buffer;
	const Shader * m_Shader;
public:
	Renderer();
	~Renderer();

	void LoadBuffers(const VertexArray * va, const Buffer * buffer);
	void AddShader(const Shader * shader);
	void Draw();
	void CreateRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
};

