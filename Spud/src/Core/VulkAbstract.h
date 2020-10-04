#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//#define VMA_IMPLEMENTATION
//#include <vulkanAlloc/vk_mem_alloc.h>

#include <cstdint>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <optional>
#include <algorithm>

namespace Spud {

	struct ManagerCreateInfo
	{
		uint32_t width;
		uint32_t height;
		bool enableValidation;
		std::vector<const char*> validationLayers;
		std::vector<const char*> deviceExtensions;
		const char* appName;
		uint32_t swapChainImageCount = 8;
		uint32_t nThreads;
	};

	struct mgGraphicsPipeline {
		VkPipelineLayout pipelineLayout;
		VkPipeline graphicsPipeline;
		std::set<uint32_t> compatibleRenderPasses;
	};

	struct mgRenderPass {
		uint32_t id;
		VkRenderPass renderPass;
	};


	class VulkanManager
	{
	public:
		VulkanManager() = default;
		
		void create(const ManagerCreateInfo& createInfo);
		void destroy();

		
		bool _framebufferResized = false;

		// accessible functions for render system
		//void createRenderPass();
		//void createGraphicsPipeline();
		//void setupCommandBuffers

		// accessible data members
		VkCommandBuffer primaryCommandBuffer;


	protected:
		// members
		uint32_t _width = 800;
		uint32_t _height = 600;
		bool _enableValidation = false;
		std::vector<const char*> _validationLayers{};
		std::vector<const char*> _deviceExtensions{};
		std::string _appName;
		uint32_t _swapChainImageCount = 8;
		uint32_t _nThreads = 1;

		GLFWwindow* _window = nullptr;
		
		VkInstance _instance = VK_NULL_HANDLE;
		VkDebugUtilsMessengerEXT _debugMessenger = VK_NULL_HANDLE;
		VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
		VkDevice _logicalDevice = VK_NULL_HANDLE;
		VkSurfaceKHR _surface;

		VkQueue _graphicsQueue = VK_NULL_HANDLE;
		VkQueue _presentQueue = VK_NULL_HANDLE;

		VkSwapchainKHR _swapChain = VK_NULL_HANDLE;
		std::vector<VkImage> _swapChainImages{};
		VkFormat _swapChainImageFormat = VkFormat::VK_FORMAT_UNDEFINED;
		VkExtent2D _swapChainExtent = {};
		std::vector<VkImageView> _swapChainImageViews{};
		// framebuffers ~ imageviews


		// functions and algos
		bool checkValidationLayerSupport();
		bool checkDeviceExtensionSupport(const VkPhysicalDevice&);
		uint32_t scoreDevice(const VkPhysicalDevice&);

		void initWindow();
		void createInstance();
		void setupDebugMessenger();
		void createDevices();
		void createSwapChain();



		std::vector<const char*> getRequiredExtensions();
	};





	
}
