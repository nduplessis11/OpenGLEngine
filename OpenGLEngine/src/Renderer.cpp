#include "Renderer.h"

Renderer::Renderer()
{
	//glEnable(GL_DEPTH_TEST);
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
