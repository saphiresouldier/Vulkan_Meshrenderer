#pragma once

#include <optional>
#include <vector>

#include <vulkan/vulkan.h>
#include "WindowingSystem.h"

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return graphicsFamily.has_value() && presentFamily.has_value();
  }
};

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

namespace Saphire
{
  class VulkanBase
  {
  public:
    VulkanBase();
    virtual ~VulkanBase();

    void init(Saphire::WindowingSystem winSys);

    VkInstance getInstance();
    VkPhysicalDevice getPhysicalDevice();
    VkDevice getDevice();
    VkSurfaceKHR getSurface();
    //VkSwapchainKHR getSwapChain(); // TODO
    VkQueue getGraphicsQueue();
    VkQueue getPresentQueue();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(Saphire::WindowingSystem winSys, const VkSurfaceCapabilitiesKHR& capabilities);

  private:
    void createInstance();
    //TODO: setupDebugMessenger();
    void createSurface(Saphire::WindowingSystem winSys);
    void pickPhysicalDevice();
    void createLogicalDevice();

    bool checkValidationLayerSupport();
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  
    // members -------------
    VkInstance instance;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkSurfaceKHR surface;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
  };
}