#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Saphire
{
  class WindowingSystem
  {

  public:
    WindowingSystem();
    virtual ~WindowingSystem();

    void initWindow();
    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
    VkResult createVulkanWindowSurface(VkInstance instance, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);

    GLFWwindow* getWindow() const;
    bool shouldWindowClose() const;
    void pollEvents();
    void getWindowSize(int* width, int* height) const;
    void waitEvents();
    void destroyAndTerminate();

  private:
    GLFWwindow* window;
  };
}
