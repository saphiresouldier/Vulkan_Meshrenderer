#include "WindowingSystem.h"

//#include "ViewerApplication.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

namespace Saphire
{
  WindowingSystem::WindowingSystem()
  {
  }


  WindowingSystem::~WindowingSystem()
  {
  }

  void WindowingSystem::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan App", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
  }

  void WindowingSystem::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    //auto app = reinterpret_cast<ViewerApplication*>(glfwGetWindowUserPointer(window));
    //app->setFramebufferResized(true);
  }

  GLFWwindow* WindowingSystem::getWindow() const
  {
    return window;
  }

  bool WindowingSystem::shouldWindowClose() const
  {
    return glfwWindowShouldClose(window);
  }

  void WindowingSystem::pollEvents()
  {
    return glfwPollEvents();
  }

  void WindowingSystem::getWindowSize(int* width, int* height) const
  {
    return glfwGetFramebufferSize(window, width, height);
  }

  void WindowingSystem::waitEvents()
  {
    glfwWaitEvents();
  }

  VkResult WindowingSystem::createVulkanWindowSurface(VkInstance instance, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface)
  {
    return glfwCreateWindowSurface(instance, window, nullptr, surface);
  }

  void WindowingSystem::destroyAndTerminate()
  {
    glfwDestroyWindow(window);

    glfwTerminate();
  }
}
