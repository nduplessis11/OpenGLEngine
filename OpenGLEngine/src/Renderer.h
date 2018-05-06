#pragma once
#include <GL/glew.h>

#include "Shader.h"
#include "Mesh.h"

#include "glm/glm.hpp"

class Renderer
{
private:
	const Shader * m_Shader;
	glm::mat4 m_Model;
public:
	Renderer();
	~Renderer();
	void Draw(Mesh & mesh, const Shader & shader);
};

