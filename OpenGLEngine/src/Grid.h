#pragma once

#include <vector>

#include <glm/glm.hpp>

struct GridLine
{
	glm::vec3 start;
	glm::vec4 start_color;
	glm::vec2 start_texture;
	glm::vec3 finish;
	glm::vec4 finish_color;
	glm::vec2 end_texture;
};

struct Grid
{
	std::vector<GridLine> gridlines;
	std::vector<glm::uvec2> indices;
};

Grid createGrid(int lineCount)
{
	int totalLineCount = (lineCount * 2) + 1;
	Grid grid;
	float x = -lineCount;
	float z = lineCount;
	unsigned int index = 0;

	for (int i = 0; i < totalLineCount; i++)
	{
		GridLine gridline
		{
			glm::vec3(x, 0.0f, z),
			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
			glm::vec2(0.0f),
			glm::vec3(x, 0.0f, -z), 
			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
			glm::vec2(0.0f)
		};

		x += 1.0f;
		grid.gridlines.push_back(gridline);
		grid.indices.push_back(glm::uvec2(index, index+1));
		index += 2;
	}

	x = lineCount;
	z = -lineCount;

	for (int i = 0; i < totalLineCount; i++)
	{
		GridLine gridline
		{ 
			glm::vec3(x, 0.0f, z), 
			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f), 
			glm::vec2(0.0f),
			glm::vec3(-x, 0.0f, z), 
			glm::vec4(1.0f, 0.0f, 0.0f, 1.0f),
			glm::vec2(0.0f)
		};

		z += 1.0f;
		grid.gridlines.push_back(gridline);
		grid.indices.push_back(glm::uvec2(index, index + 1));
		index += 2;
	}

	return grid;
}

unsigned int gridFloatCount(const Grid& grid)
{
	unsigned int size = (sizeof(GridLine) * grid.gridlines.size());
	unsigned int floatCount = size / sizeof(GLfloat);

	return floatCount;
}

unsigned int gridIndexCount(const Grid& grid)
{
	unsigned int size = (sizeof(glm::uvec2) * grid.indices.size());
	unsigned int indexCount = size / sizeof(GLuint);

	return indexCount;
}