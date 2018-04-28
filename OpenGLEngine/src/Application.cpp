#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexArray.h"
#include "Buffer.h"
#include "Renderer.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	float points[] = {
		0.0f,  0.5f,  0.0f,
		0.5f, -0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	float points2[] = {
		-0.5f,  0.5f,  0.0f,
		0.0f,  0.5f,  0.0f,
		-0.5f, -0.5f,  0.0f
	};

	VertexArray va;

	Buffer buffer;
	buffer.AddData(points, 9);

	Renderer renderer;
	renderer.LoadBuffers(&va, &buffer);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer.Draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}