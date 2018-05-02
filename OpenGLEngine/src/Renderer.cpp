#include "Renderer.h"

#include <GL/glew.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::AddVertexData(const VertexArray * va, const VertexBuffer & buffer)
{
	m_Va = va;

	m_Va->Bind();
	buffer.Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_Va->Unbind();
	buffer.Unbind();
}

void Renderer::AddShader(const Shader * shader)
{
	m_Shader = shader;
}

void Renderer::Draw()
{
	m_Shader->Bind();
	m_Va->Bind();

	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	m_Shader->Unbind();
	m_Va->Unbind();
}
