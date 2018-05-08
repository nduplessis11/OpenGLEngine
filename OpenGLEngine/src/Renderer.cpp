#include "Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

Renderer::~Renderer()
{
}

void Renderer::Draw(ModelInstance & modelInstance)
{
	modelInstance.asset->Shader->Bind();
	modelInstance.asset->Shader->SetModel(modelInstance.transform);
	modelInstance.asset->Mesh.SetDraw();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);

	modelInstance.asset->Shader->Unbind();
	modelInstance.asset->Mesh.UnsetDraw();
}
