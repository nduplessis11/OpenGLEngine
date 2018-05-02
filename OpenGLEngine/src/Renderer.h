#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"

#include <GL/glew.h>

class Renderer
{
private:
	const Shader * m_Shader;
public:
	Renderer();
	~Renderer();
	void Draw(const VertexArray & vertexArray, const Shader & shader) const;
};

