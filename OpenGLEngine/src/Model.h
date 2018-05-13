#pragma once

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

struct ModelAsset
{
	Shader* Shader;
	Texture* Texture;
	Mesh Mesh;
};

struct ModelInstance
{
	ModelAsset* asset;
	glm::mat4 transform;
};