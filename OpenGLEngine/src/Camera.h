#pragma once

#include <glm/glm.hpp>

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
public:
	Camera();
	void MoveForward(float deltaTime);
	void MoveBackward(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveRight(float deltaTime);

	void ProcessMouseMovement(float xoffset, float yoffset);

	inline glm::mat4 GetView() const { return m_View; }
};