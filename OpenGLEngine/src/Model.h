#pragma once

#include "Shader.h"
#include "Mesh.h"

struct ModelAsset
{
	Shader* Shader;
	Mesh Mesh;
};

struct ModelInstance
{
	ModelAsset* asset;
	glm::mat4 transform;
};