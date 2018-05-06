#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	GLfloat points[] = {
		-0.5f, -0.5f,  0.0f,
		 1.0f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.0f,
		 0.0f,  1.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.0f,
		 0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.0f,
		 0.0f,  1.0f,  1.0f, 1.0f
	};

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	{
		Shader shader("res/shaders/shader.vs", "res/shaders/shader.fs");
		Mesh mesh(points, sizeof(points) / sizeof(GLfloat), indices, 6);
		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			renderer.Draw(mesh, shader);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}