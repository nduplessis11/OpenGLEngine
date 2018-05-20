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
#include "Light.h"
#include "VertexLayout.h"

Camera camera;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

float lastX = 400, lastY = 300;
bool firstMouse = true;

void processInput(GLFWwindow *window, Camera& camera)
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera.MoveForward(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera.MoveBackward(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera.MoveLeft(deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera.MoveRight(deltaTime);

}

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouseCallback);

	{
		Shader basicShader("res/shaders/basic_vs.shader", "res/shaders/basic_fs.shader");
		Shader gridShader("res/shaders/grid_vs.shader", "res/shaders/grid_fs.shader");
		Shader lightShader("res/shaders/light_vs.shader", "res/shaders/light_fs.shader");

		Texture texture("res/textures/container.jpg");

		Light light = createLight(1.0f);
		GLfloat* lpoints = &light.front.topLeft.x;
		GLuint* lightIndices = &light.indices[0].x;

		GLuint light_fc = lightFloatCount(light);
		GLuint light_ic = lightIndexCount(light);
		VertexLayout lightLayout = createLightLayout();

		Mesh meshLight(lpoints, light_fc, lightIndices, light_ic, GL_TRIANGLES, lightLayout);
		ModelAsset modelAssetLight{ &lightShader, NULL, meshLight };
		ModelInstance modelInstanceLight{ &modelAssetLight, glm::translate(glm::mat4(1.0f), glm::vec3(4.0f, 3.0f, -3.0f)) };

		lightShader.Bind();
		lightShader.SetObjectColor(glm::vec3(1.0f, 0.5f, 0.31f));
		lightShader.SetLightColor(glm::vec3(1.0f, 1.0f, 1.0f));
		lightShader.Unbind();


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
		modelInstances.push_back(modelInstanceLight);
		
		
		Renderer renderer;

		while (!glfwWindowShouldClose(window))
		{
			processInput(window, camera);
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