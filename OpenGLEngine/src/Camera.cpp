#include "Camera.h"

#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera()
{
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f);

	glm::vec3 target = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 direction = glm::normalize(position - target);

	glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 right = glm::normalize(glm::cross(worldUp, direction));

	glm::vec3 up = glm::cross(direction, right);

	glm::mat4 view = glm::lookAt(glm::vec3(5.0f, 5.0f, 3.0f),
								 glm::vec3(0.0f, 0.0f, 0.0f),
								 glm::vec3(0.0f, 1.0f, 0.0f));

	m_View = view;
}