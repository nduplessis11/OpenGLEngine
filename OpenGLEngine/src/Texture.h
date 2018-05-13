#pragma once

#include <GL/glew.h>

#include <string>

#include "stb/stb_image.h"

class Texture
{
private:
	GLuint m_Id;
public:
	Texture(const std::string texturePath);
	~Texture();

	void Bind();
	void Unbind();
};
