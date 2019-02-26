#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <optional>

const int WIDTH = 800;
const int HEIGHT = 600;

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif // NDEBUG

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	bool isComplete() {
		return graphicsFamily.has_value();
	}
};

class HelloTriangleApplication {
public: 
	void run();
private:
	//fields
	GLFWwindow* window;
	VkInstance instance;
	VkDebugUtilsMessengerEXT callback;

	//funcs
	void initWindow();
	void initVulkan();
	void setupDebugCallback();
	void mainLoop();
	void cleanup();
	void createInstance();
	void pickPhysicalDevice();
	bool checkValidationLayerSupport();
	bool isDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	std::vector<const char*> getRequiredExtensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, // severity. Can be one of four: verbose, info, warning or error
		VkDebugUtilsMessageTypeFlagsEXT messageType, // type. can have one of three values: general, validation or performance
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, // data, contains info on error
		void* pUserData); // allowes for input of own data (pointer to HelloTriangleApplication class to check fields)

};