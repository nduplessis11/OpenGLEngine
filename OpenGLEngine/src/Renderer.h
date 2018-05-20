#pragma once
#include <GL/glew.h>

#include "Shader.h"
#include "Mesh.h"
#include "Model.h"
#include "Camera.h"

#include "glm/glm.hpp"

#include <vector>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Draw(const Camera& camera, const ModelInstance& modelInstance);
private:
	glm::mat4 m_Perspective;
};

