#pragma once

#include "WindowingSystem.h"
#include "RenderEngine.h"
#include "Scene.h"

class ViewerApplication
{
public:
  void run();
  void setFramebufferResized(bool value);

private:
  void mainLoop();
  void cleanup();

  // members
  Saphire::WindowingSystem windowingSystem;
  Saphire::RenderEngine renderEngine;
  Saphire::Scene scene;
  bool framebufferResized{ false };
};