#pragma once

#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

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
};

