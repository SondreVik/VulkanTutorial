
#include "HelloTriangleApplication.h"

// public
void HelloTriangleApplication::run() {
	initWindow();
	initVulkan();
	mainLoop();
	cleanup();
}

//private
void HelloTriangleApplication::initWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // do not create an OpenGL context
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // disable window rezise
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr); // create empty window
}

void HelloTriangleApplication::initVulkan() {

}

void HelloTriangleApplication::mainLoop() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents(); // while window is up. Poll events. Now we have an aevent loop.
	}
}

void HelloTriangleApplication::cleanup() {
	glfwDestroyWindow(window);

	glfwTerminate();
}