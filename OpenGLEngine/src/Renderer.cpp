#include "Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <vector>

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

Renderer::~Renderer()
{
}

void Renderer::Draw(const Camera& camera, const ModelInstance& modelInstance)
{
		modelInstance.asset->Shader->Bind();
		modelInstance.asset->Shader->SetModel(modelInstance.transform);

		if (modelInstance.asset->Texture)
		{
			modelInstance.asset->Texture->Bind();
		}

		modelInstance.asset->Mesh.SetDraw();
		modelInstance.asset->Shader->SetView(camera.GetView());

		glDrawElements(modelInstance.asset->Mesh.GetDrawMode(), modelInstance.asset->Mesh.GetIndexCount(), GL_UNSIGNED_INT, NULL);

		if (modelInstance.asset->Texture)
		{
			modelInstance.asset->Texture->Unbind();
		}
		modelInstance.asset->Shader->Unbind();
		modelInstance.asset->Mesh.UnsetDraw();
}
