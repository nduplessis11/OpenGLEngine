#pragma once
#include <GL/glew.h>

#include "Shader.h"
#include "Mesh.h"
#include "Model.h"

#include "glm/glm.hpp"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void Draw(ModelInstance & modelInstance);
};

