#include "Renderer.h"

#include <GL/glew.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Draw(Mesh & mesh, const Shader & shader) const
{
	shader.Bind();
	mesh.SetDraw();

	glClear(GL_COLOR_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);

	shader.Unbind();
	mesh.UnsetDraw();
}
