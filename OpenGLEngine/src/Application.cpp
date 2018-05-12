#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"
#include "Model.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Grid.h"


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


		Grid grid = createGrid(5);
		GLfloat* gridLines = &grid.gridlines[0].start.x;
		GLuint* gridIndices = &grid.indices[0].x;

		GLuint floatCount = gridFloatCount(grid);
		GLuint indexCount = gridIndexCount(grid);

		Mesh meshGrid(gridLines, floatCount, gridIndices, indexCount, GL_LINES);
		ModelAsset modelAssetGrid{ &shader, meshGrid };
		ModelInstance modelInstanceGrid{ &modelAssetGrid, glm::mat4(1.0f) };


		ModelAsset modelAssetCube { &shader, Mesh(points, sizeof(points) / sizeof(GLfloat), indices, 36, GL_TRIANGLES) };
		ModelInstance modelInstanceCube { &modelAssetCube, glm::mat4(1.0f) };
	
		std::vector<ModelInstance> modelInstances;
		modelInstances.push_back(modelInstanceCube);
		modelInstances.push_back(modelInstanceGrid);

		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			std::vector<ModelInstance>::const_iterator it;
			for (it = modelInstances.begin(); it != modelInstances.end(); it++)
			{
				renderer.Draw(*it);
			}
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}