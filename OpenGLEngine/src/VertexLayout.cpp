#include "VertexLayout.h"

VertexLayout createGridLayout()
{
	VertexLayout vertexLayout;

	VertexAttribute position{ 0, 3, 0 };
	vertexLayout.attributes.push_back(position);
	vertexLayout.stride = position.dimensionCount * sizeof(float);

	VertexAttribute color{ 1, 4, vertexLayout.stride };
	vertexLayout.attributes.push_back(color);
	vertexLayout.stride += color.dimensionCount * sizeof(float);

	return vertexLayout;
}

VertexLayout createBasicLayout()
{
	VertexLayout vertexLayout;

	VertexAttribute position{ 0, 3, 0 };
	vertexLayout.attributes.push_back(position);
	vertexLayout.stride = position.dimensionCount * sizeof(float);

	VertexAttribute texture{ 1, 2, vertexLayout.stride };
	vertexLayout.attributes.push_back(texture);
	vertexLayout.stride += texture.dimensionCount * sizeof(float);

	return vertexLayout;
}

VertexLayout createLightLayout()
{
	VertexLayout vertexLayout;

	VertexAttribute position{ 0, 3, 0 };
	vertexLayout.attributes.push_back(position);
	vertexLayout.stride = position.dimensionCount * sizeof(float);

	return vertexLayout;
}