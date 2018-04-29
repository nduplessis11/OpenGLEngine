#include "Renderer.h"

#include <GL/glew.h>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::LoadBuffers(const VertexArray * va, const Buffer * buffer)
{
	m_Buffer = buffer;
	m_Va = va;

	m_Va->Bind();
	m_Buffer->Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_Va->Unbind();
	m_Buffer->Unbind();
}

void Renderer::AddShader(const Shader * shader)
{
	m_Shader = shader;
}

void Renderer::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	m_Shader->UseProgram();
	m_Va->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Renderer::CreateRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
{
	GLfloat positions[] = {
		x, y, 0.0f,
		x+(width), y - height, 0.0f,
		x,y-height, 0.0f,

		x, y, 0.0f,
		x+width, y, 0.0f,
		x + (width), y - height, 0.0f,
	};
	
	m_Va = new VertexArray();

	m_Buffer = new Buffer();
	m_Buffer->AddData(positions, 18);

	m_Va->Bind();
	m_Buffer->Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_Va->Unbind();
	m_Buffer->Unbind();
}
