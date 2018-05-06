#include "Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Renderer::Renderer()
	: m_Model(1.0f)
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

Renderer::~Renderer()
{
}

void Renderer::Draw(Mesh & mesh, const Shader & shader)
{
	shader.Bind();
	glm::mat4 model(1.0f);
	model = glm::translate(model, mesh.GetPosition());
	model = glm::rotate(model, glm::radians(mesh.GetRotation().z), glm::vec3(0.0f, 0.0f, 1.0f));

	shader.SetModel(model);

	mesh.SetDraw();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);

	shader.Unbind();
	mesh.UnsetDraw();
}
