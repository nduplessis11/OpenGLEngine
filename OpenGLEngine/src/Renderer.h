#pragma once

#include "VertexArray.h"
#include "Buffer.h"

class Renderer
{
private:
	VertexArray * m_Va;
	Buffer * m_Buffer;

public:
	Renderer();
	~Renderer();

	void LoadBuffers(VertexArray * va, Buffer * buffer);
	void Draw();
};

