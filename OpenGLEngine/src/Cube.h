#pragma once

#include <vector>

#include <glm/glm.hpp>

struct CubeFace
{
	glm::vec3 topLeft;
	glm::vec4 topLeftColor;
	glm::vec2 topLeftTex;

	glm::vec3 bottomLeft;
	glm::vec4 bottomLeftColor;
	glm::vec2 bottomLeftTex;

	glm::vec3 bottomRight;
	glm::vec4 bottomRightColor;
	glm::vec2 bottomRightTex;

	glm::vec3 topRight;
	glm::vec4 topRightColor;
	glm::vec2 topRightTex;
};

struct Cube
{
	CubeFace front;
	CubeFace back;
	std::vector<glm::uvec3> indices;
};

Cube createCube(float size)
{
	Cube cube;

	float leftCoord = -(size / 2);
	float rightCoord = (size / 2);
	float topCoord = (size / 2);
	float bottomCoord = -(size / 2);
	float frontCoord = (size / 2);
	float backCoord = -(size / 2);

	CubeFace cubeFaceFront
	{
		// 0
		glm::vec3(leftCoord, topCoord, frontCoord),
		glm::vec4(1.0f,  0.0f,  0.0f, 1.0f),
		glm::vec2(0.0f, 1.0f),

		// 1
		glm::vec3(leftCoord, bottomCoord, frontCoord),
		glm::vec4(0.0f,  1.0f,  0.0f, 1.0f),
		glm::vec2(0.0f, 0.0f),

		// 2
		glm::vec3(rightCoord, bottomCoord, frontCoord),
		glm::vec4(0.0f,  0.0f,  1.0f, 1.0f),
		glm::vec2(1.0f, 0.0f),

		// 3
		glm::vec3(rightCoord, topCoord, frontCoord),
		glm::vec4(0.0f,  1.0f,  1.0f, 1.0f),
		glm::vec2(1.0f, 1.0f),
	};

	cube.front = cubeFaceFront;
	cube.indices.push_back(glm::uvec3(0, 1, 2));
	cube.indices.push_back(glm::uvec3(0, 2, 3));

	CubeFace cubeFaceBack
	{
		// mirror left and right so face is backwards

		// 4
		glm::vec3(-leftCoord, topCoord, backCoord),
		glm::vec4(1.0f,  0.0f,  0.0f, 1.0f),
		glm::vec2(0.0f, 1.0f),

		// 5
		glm::vec3(-leftCoord, bottomCoord, backCoord),
		glm::vec4(0.0f,  1.0f,  0.0f, 1.0f),
		glm::vec2(0.0f, 0.0f),

		// 6
		glm::vec3(-rightCoord, bottomCoord, backCoord),
		glm::vec4(0.0f,  0.0f,  1.0f, 1.0f),
		glm::vec2(1.0f, 0.0f),

		// 7
		glm::vec3(-rightCoord, topCoord, backCoord),
		glm::vec4(0.0f,  1.0f,  1.0f, 1.0f),
		glm::vec2(1.0f, 1.0f),
	};

	cube.back = cubeFaceBack;
	cube.indices.push_back(glm::uvec3(4, 5, 6));
	cube.indices.push_back(glm::uvec3(4, 6, 7));

	// left
	cube.indices.push_back(glm::uvec3(7, 6, 0));
	cube.indices.push_back(glm::uvec3(0, 6, 1));

	// right
	cube.indices.push_back(glm::uvec3(3, 2, 5));
	cube.indices.push_back(glm::uvec3(3, 5, 4));

	// top
	cube.indices.push_back(glm::uvec3(7, 0, 4));
	cube.indices.push_back(glm::uvec3(0, 3, 4));

	// bottom
	cube.indices.push_back(glm::uvec3(1, 6, 2));
	cube.indices.push_back(glm::uvec3(6, 5, 2));
		
	return cube;
}

unsigned int cubeFloatCount(const Cube& cube)
{
	unsigned int floatCount = (2 * sizeof(CubeFace)) / sizeof(float);
	return floatCount;
}

unsigned int cubeIndexCount(const Cube& cube)
{
	unsigned int size = (sizeof(glm::uvec3) * cube.indices.size());
	unsigned int indexCount = size / sizeof(unsigned int);

	return indexCount;
}