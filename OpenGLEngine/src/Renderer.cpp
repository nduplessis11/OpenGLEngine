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

	glm::mat4 view(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
	view = glm::rotate(view, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	modelInstance.asset->Shader->SetView(view);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
	glDrawElements(GL_LINES, 42, GL_UNSIGNED_INT, NULL);

	modelInstance.asset->Shader->Unbind();
	modelInstance.asset->Mesh.UnsetDraw();
}
