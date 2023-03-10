#pragma once

#include <vector>
#include <string>
#include <utility>

#include "SceneObject.h"

namespace Saphire
{
  class Scene
  {
    public:
      Scene();
      virtual ~Scene();

      bool add(SceneObject* object);
      bool add(SceneObject* object, std::string name);
      bool remove(std::string name);
      void clear();
      SceneObject* get(std::string name);
      SceneObject* get(uint32_t index);
      size_t getSize() const;

      std::vector<std::string> getObjectNames() const;
      std::vector<SceneObject*> getSceneObjects();

    private:
      std::vector<std::pair<const std::string, SceneObject*>> objects;

      SceneObject* root;

      bool uniqueName(std::string name);
      void addInternal(SceneObject* object, std::string name);
  };
}
