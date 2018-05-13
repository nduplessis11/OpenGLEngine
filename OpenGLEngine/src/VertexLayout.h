#pragma once

#include <vector>

struct VertexAttribute
{
	unsigned int location;
	unsigned int dimensionCount;
	unsigned int offset;
};

struct VertexLayout
{
	std::vector<VertexAttribute> attributes;
	int stride;
};

VertexLayout createGridLayout();
VertexLayout createBasicLayout();