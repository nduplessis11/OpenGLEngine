#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"

#include <GL/glew.h>

class Renderer
{
private:
	const VertexArray * m_Va;
	const Shader * m_Shader;
public:
	Renderer();
	~Renderer();

	void AddVertexData(const VertexArray * va, const VertexBuffer & buffer);
	void AddShader(const Shader * shader);
	void Draw();
};

