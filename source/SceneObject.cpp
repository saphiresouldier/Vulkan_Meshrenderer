#include "SceneObject.h"

namespace Saphire
{
  SceneObject::SceneObject() : transformationMatrix(glm::mat4(1.0f))
  {
  }

  SceneObject::SceneObject(glm::mat4 mat) : transformationMatrix(mat) 
  {
  }

  SceneObject::~SceneObject() {}

  void SceneObject::SetTransformationMatrix(const glm::mat4x4 mat)
  {
    transformationMatrix = mat;
  }

  glm::mat4 SceneObject::getTransformationMatrix() const
  {
    return transformationMatrix;
  }
}