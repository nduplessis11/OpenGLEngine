#include "Renderer.h"

#include <GL/glew.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Draw(const VertexArray & vertexArray, const Shader & shader) const
{
	shader.Bind();
	vertexArray.Bind();

	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	shader.Unbind();
	vertexArray.Unbind();
}

void Renderer::Draw(Mesh & mesh, const Shader & shader) const
{
	shader.Bind();
	mesh.SetDraw();

	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	shader.Unbind();
	mesh.UnsetDraw();
}
