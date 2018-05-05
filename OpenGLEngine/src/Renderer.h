#pragma once
#include <GL/glew.h>

#include "Shader.h"
#include "Mesh.h"

class Renderer
{
private:
	const Shader * m_Shader;
public:
	Renderer();
	~Renderer();
	void Draw(Mesh & mesh, const Shader & shader) const;
};

