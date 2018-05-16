#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "Shader.h"
#include "Mesh.h"
#include "Model.h"
#include "Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "stb/stb_image.h"

#include "Grid.h"
#include "Cube.h"
#include "VertexLayout.h"


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

	{
		Shader basicShader("res/shaders/basic_vs.shader", "res/shaders/basic_fs.shader");
		Shader gridShader("res/shaders/grid_vs.shader", "res/shaders/grid_fs.shader");

		Texture texture("res/textures/container.jpg");

		Cube cube = createCube(1.0f);
		GLfloat* points = &cube.front.topLeft.x;
		GLuint* cubeIndices = &cube.indices[0].x;
		
		GLuint cube_fc = cubeFloatCount(cube);
		GLuint cube_ic = cubeIndexCount(cube);
		VertexLayout basicLayout = createBasicLayout();

		Mesh meshCube(points, cube_fc, cubeIndices, cube_ic, GL_TRIANGLES, basicLayout);
		ModelAsset modelAssetCube{ &basicShader, &texture, meshCube };
		ModelInstance modelInstanceCube{ &modelAssetCube, glm::mat4(1.0f) };


		Grid grid = createGrid(5);
		GLfloat* gridLines = &grid.gridlines[0].start.x;
		GLuint* gridIndices = &grid.indices[0].x;

		GLuint grid_fc = gridFloatCount(grid);
		GLuint grid_ic = gridIndexCount(grid);
		VertexLayout gridLayout = createGridLayout();

		Mesh meshGrid(gridLines, grid_fc, gridIndices, grid_ic, GL_LINES, gridLayout);
		ModelAsset modelAssetGrid{ &gridShader, NULL, meshGrid };
		ModelInstance modelInstanceGrid{ &modelAssetGrid, glm::mat4(1.0f) };
	
		std::vector<ModelInstance> modelInstances;
		modelInstances.push_back(modelInstanceCube);
		modelInstances.push_back(modelInstanceGrid);
		
		Camera camera;
		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			std::vector<ModelInstance>::const_iterator it;
			for (it = modelInstances.begin(); it != modelInstances.end(); it++)
			{
				renderer.Draw(camera, *it);
			}
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	glfwTerminate();
	return 0;
}