#pragma once

#include <vector>

#include <glm/glm.hpp>

struct LightFace
{
	glm::vec3 topLeft;
	glm::vec3 bottomLeft;
	glm::vec3 bottomRight;
	glm::vec3 topRight;
};

struct Light
{
	LightFace front;
	LightFace back;
	std::vector<glm::uvec3> indices;
};

Light createLight(float size)
{
	Light light;

	float leftCoord = -(size / 2);
	float rightCoord = (size / 2);
	float topCoord = (size / 2);
	float bottomCoord = -(size / 2);
	float frontCoord = (size / 2);
	float backCoord = -(size / 2);

	LightFace lightFaceFront
	{
		// 0
		glm::vec3(leftCoord, topCoord, frontCoord),

		// 1
		glm::vec3(leftCoord, bottomCoord, frontCoord),

		// 2
		glm::vec3(rightCoord, bottomCoord, frontCoord),

		// 3
		glm::vec3(rightCoord, topCoord, frontCoord)
	};

	light.front = lightFaceFront;
	light.indices.push_back(glm::uvec3(0, 1, 2));
	light.indices.push_back(glm::uvec3(0, 2, 3));

	LightFace lightFaceBack
	{
		// mirror left and right so face is backwards

		// 4
		glm::vec3(-leftCoord, topCoord, backCoord),

		// 5
		glm::vec3(-leftCoord, bottomCoord, backCoord),

		// 6
		glm::vec3(-rightCoord, bottomCoord, backCoord),

		// 7
		glm::vec3(-rightCoord, topCoord, backCoord),
	};

	light.back = lightFaceBack;
	light.indices.push_back(glm::uvec3(4, 5, 6));
	light.indices.push_back(glm::uvec3(4, 6, 7));

	// left
	light.indices.push_back(glm::uvec3(7, 6, 0));
	light.indices.push_back(glm::uvec3(0, 6, 1));

	// right
	light.indices.push_back(glm::uvec3(3, 2, 5));
	light.indices.push_back(glm::uvec3(3, 5, 4));

	// top
	light.indices.push_back(glm::uvec3(7, 0, 4));
	light.indices.push_back(glm::uvec3(0, 3, 4));

	// bottom
	light.indices.push_back(glm::uvec3(1, 6, 2));
	light.indices.push_back(glm::uvec3(6, 5, 2));

	return light;
}

unsigned int lightFloatCount(const Light& light)
{
	unsigned int floatCount = (2 * sizeof(LightFace)) / sizeof(float);
	return floatCount;
}

unsigned int lightIndexCount(const Light& light)
{
	unsigned int size = (sizeof(glm::uvec3) * light.indices.size());
	unsigned int indexCount = size / sizeof(unsigned int);

	return indexCount;
}