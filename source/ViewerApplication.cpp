#include "ViewerApplication.h"

void ViewerApplication::run()
{
  windowingSystem.initWindow();
  renderEngine.init(windowingSystem);
  mainLoop();
  cleanup();
}

void ViewerApplication::mainLoop() {
  while (!windowingSystem.shouldWindowClose()) {
    windowingSystem.pollEvents();
    renderEngine.drawFrame(windowingSystem);
  }

  renderEngine.wait();
}

void ViewerApplication::cleanup() 
{
  renderEngine.cleanup();
  windowingSystem.destroyAndTerminate();
}

void ViewerApplication::setFramebufferResized(bool value)
{
  framebufferResized = value;
}