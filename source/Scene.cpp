#include "Scene.h"

#include <iostream>
#include <stdexcept>

namespace Saphire
{
  Scene::Scene() 
  {
    root = new SceneObject(glm::mat4(1.0f));
    add(root, "root");
  }

  Scene::~Scene() 
  {
    delete root;
  }

  bool Scene::add(SceneObject* object)
  {
    auto objectcount = getSize();
    const std::string name = "Object " + std::to_string(objectcount);

    while (!uniqueName(name))
    {
      const std::string name = "Object " + std::to_string(objectcount++);
    }

    addInternal(object, name);

    return true;
  }

  bool Scene::add(SceneObject* object, std::string name)
  {
    if (uniqueName(name))
    {
      addInternal(object, name);
      return true;
    }
    else {
      throw std::runtime_error("There already exists an object named " + name + " in the Scene!");
      return false;
    } 
  }

  bool Scene::remove(const std::string name)
  {
    for (int i = 0; i < getSize(); i++)
    {
      if (objects[i].first == name)
      {
        //objects.erase(objects.begin());
        std::vector<std::pair<const std::string, SceneObject*>>::iterator it = objects.begin();
        std::advance(it, i);
        //objects.erase(it); // TODO
        //objects.erase(std::remove(objects.begin(), objects.end(), objects[i]), objects.end());
        return false;
      }
    }

    return false;
  }

  void Scene::clear()
  {
    objects.clear();
    add(root, "root");
  }

  SceneObject* Scene::get(std::string name)
  {
    for (unsigned int i = 0; i < getSize(); i++)
    {
      if (objects[i].first == name)
      {
        return objects[i].second;
      }
    }

    throw std::runtime_error("No object named " + name + " in the Scene!");
    return nullptr;
  }

  SceneObject* Scene::get(uint32_t index)
  {
    if (index < getSize())
    {
      return objects[index].second;
    }
    else
    {
      throw std::runtime_error("no object in scene with index " + index);
      return nullptr;
    }
  }

  size_t Scene::getSize() const
  {
    return objects.size();
  }

  std::vector<std::string> Scene::getObjectNames() const
  {
    std::vector<std::string> names;

    for (auto& obj : objects) {
      names.push_back(obj.first);
    }

    return names;
  }

  std::vector<SceneObject*> Scene::getSceneObjects()
  {
    std::vector<SceneObject*> sObj;

    for (auto& obj : objects) {
      sObj.push_back(obj.second);
    }

    return sObj;
  }

  bool Scene::uniqueName(std::string name)
  {
    bool unique = true;

    for (auto& obj : objects)
    {
      if (obj.first == name) {
        unique = false;
        break;
      }
    }

    return unique;
  }

  void Scene::addInternal(SceneObject* object, std::string name)
  {
    objects.push_back(std::pair<const std::string, SceneObject*>(name, object));

    std::cout << "Added object " << name << " to scene!" << std::endl;
  }
}