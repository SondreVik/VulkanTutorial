#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;

class HelloTriangleApplication {
public: 
	void run();
private:
	//fields
	GLFWwindow* window;
	VkInstance instance;

	//funcs
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();
	void createInstance();
	
};