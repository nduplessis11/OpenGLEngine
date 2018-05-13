#include "Texture.h"

Texture::Texture(const std::string texturePath)
	: m_Id(0)
{
	glGenTextures(1, &m_Id);

	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);

	Unbind();
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_Id);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_Id);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}