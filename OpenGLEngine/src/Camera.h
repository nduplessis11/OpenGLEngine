#pragma once

#include <glm/glm.hpp>

class Camera
{
private:
	glm::mat4 m_View;
public:
	Camera();
	inline glm::mat4 GetView() const { return m_View; }
};