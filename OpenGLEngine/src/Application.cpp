#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"
#include "Model.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

GLfloat grid[308];

GLuint gridIndices[] = {
	0, 1,
	2, 3,
	4, 5,
	6, 7,
	8, 9,
	10, 11,
	12, 13,
	14, 15,
	16, 17,
	18, 19,
	20, 21,

	22, 23,
	24, 25,
	26, 27,
	28, 29,
	30, 31,
	32, 33,
	34, 35,
	36, 37,
	38, 39,
	40, 41
};

void fillGrid()
{
	GLfloat x = -5.0f;
	for (int i = 0; i < 154; i+=14)
	{
		grid[i] = x;
		grid[i + 1] = 0.0f;
		grid[i + 2] = 5.0f;

		if (x == 0.0f)
		{
			grid[i + 3] = 1.0f;
			grid[i + 4] = 0.0f;
			grid[i + 5] = 0.0f;
			grid[i + 6] = 1.0f;
		}
		else
		{
			grid[i + 3] = 0.0f;
			grid[i + 4] = 1.0f;
			grid[i + 5] = 0.0f;
			grid[i + 6] = 1.0f;
		}

		grid[i + 7] = x;
		grid[i + 8] = 0.0f;
		grid[i + 9] = -5.0f;

		if (x == 0.0f)
		{
			grid[i + 3] = 1.0f;
			grid[i + 4] = 0.0f;
			grid[i + 5] = 0.0f;
			grid[i + 6] = 1.0f;
		}
		else
		{
			grid[i + 10] = 0.0f;
			grid[i + 11] = 1.0f;
			grid[i + 12] = 0.0f;
			grid[i + 13] = 1.0f;
		}

		x += 1.0f;
	}

	GLfloat z = -5.0f;
	for (int i = 154; i < 308; i += 14)
	{
		grid[i] = 5.0f;
		grid[i + 1] = 0.0f;
		grid[i + 2] = z;

		if (z == 0.0f)
		{
			grid[i + 10] = 0.0f;
			grid[i + 11] = 0.0f;
			grid[i + 12] = 1.0f;
			grid[i + 13] = 1.0f;
		}
		else
		{
			grid[i + 3] = 0.0f;
			grid[i + 4] = 1.0f;
			grid[i + 5] = 0.0f;
			grid[i + 6] = 1.0f;
		}

		grid[i + 7] = -5.0f;
		grid[i + 8] = 0.0f;
		grid[i + 9] = z;

		if (z == 0.0f)
		{
			grid[i + 10] = 0.0f;
			grid[i + 11] = 0.0f;
			grid[i + 12] = 1.0f;
			grid[i + 13] = 1.0f;
		}
		else
		{
			grid[i + 10] = 0.0f;
			grid[i + 11] = 1.0f;
			grid[i + 12] = 0.0f;
			grid[i + 13] = 1.0f;
		}


		z += 1.0f;
	}
}

int main(void)
{
	fillGrid();
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
		-0.5f, -0.5f,  0.5f,	1.0f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f,  1.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,	0.0f,  1.0f,  1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f,	1.0f,  0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f,  1.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f,  1.0f,  1.0f, 1.0f
	};

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3,

		4, 5, 6,
		4, 6, 7,

		4, 5, 1,
		4, 1, 0,

		3, 2, 6,
		3, 6, 7,

		4, 0, 3,
		4, 3, 7,

		5, 1, 2,
		5, 2, 6
	};

	{
		Shader shader("res/shaders/shader.vs", "res/shaders/shader.fs");
		//ModelAsset modelAsset { &shader, Mesh(points, sizeof(points) / sizeof(GLfloat), indices, 36) };
		ModelAsset modelAsset { &shader, Mesh(grid, sizeof(grid) / sizeof(GLfloat), gridIndices, 42) };
		ModelInstance modelInstance { &modelAsset, glm::mat4(1.0f) };
		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			renderer.Draw(modelInstance);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}