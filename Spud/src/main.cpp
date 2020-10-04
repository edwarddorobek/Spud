
#include "Core/VulkAbstract.h"

int main()
{
	printf("Hello Spud!\n");

	Spud::ManagerCreateInfo sysInfo;
		sysInfo.appName = "My app";
		sysInfo.enableValidation = true;
		sysInfo.height = 600;
		sysInfo.width = 800;
		sysInfo.validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};
		sysInfo.deviceExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

	Spud::VulkanManager vulkSystem;

	vulkSystem.create(sysInfo);



	// do things


	vulkSystem.destroy();

	return 0;
}