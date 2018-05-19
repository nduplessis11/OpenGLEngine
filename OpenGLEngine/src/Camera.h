#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	glm::mat4 m_View;
	glm::vec3 m_Position;
	glm::vec3 m_Front;
	glm::vec3 m_Up;

	float m_Pitch;
	float m_Yaw;

	float m_Speed;
	float m_Sensitivity;
public:
	Camera();
	void MoveForward(float deltaTime);
	void MoveBackward(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);

	void ProcessMouseMovement(float xoffset, float yoffset);

	inline glm::mat4 GetView() const { return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
	}
};