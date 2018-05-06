#pragma once

#include <GL/glew.h>

#include "glm/glm.hpp"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh
{
private:
	VertexArray m_VertexArray;
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;

	glm::vec3 m_Position;
	glm::vec3 m_Rotation;
public:
	Mesh(const GLfloat* data, GLuint count, const GLuint* indices, GLuint indexCount);
	~Mesh();

	void SetDraw();
	void UnsetDraw();

	inline glm::vec3 GetPosition(){ return m_Position; }
	inline void SetPosition(glm::vec3 position){ m_Position = position; }

	inline glm::vec3 GetRotation() { return m_Rotation; }
	inline void SetRotation(glm::vec3 rotation) { m_Rotation = rotation; }
};

