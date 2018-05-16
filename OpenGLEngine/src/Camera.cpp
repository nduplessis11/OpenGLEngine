#include "Camera.h"

#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
	m_Up = glm::vec3(0.0f, 1.0f, 0.0f);

	m_Pitch = 0.0f;
	m_Yaw = 0.0f;

	m_Speed = 2.5f;

	m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::MoveForward(float deltaTime)
{
	m_Position += deltaTime * m_Speed * m_Front;
	m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::MoveBackward(float deltaTime)
{
	m_Position -= deltaTime * m_Speed * m_Front;
	m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::MoveLeft(float deltaTime)
{
	m_Position -= deltaTime * glm::normalize(glm::cross(m_Front, m_Up)) * m_Speed;
	m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::MoveRight(float deltaTime)
{
	m_Position += deltaTime * glm::normalize(glm::cross(m_Front, m_Up)) * m_Speed;
	m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset)
{
	float sensitivity = 2.0f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	m_Yaw += xoffset;
	m_Pitch += yoffset;

	if (m_Pitch > 89.0f)
		m_Pitch = 89.0f;
	if (m_Pitch < -89.0f)
		m_Pitch = -89.0f;

	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front = glm::normalize(front);

	m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}