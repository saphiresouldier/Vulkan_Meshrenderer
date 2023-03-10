#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>

namespace Saphire
{
  class SceneObject
  {
    public:
      SceneObject();
      SceneObject(glm::mat4 mat);
      virtual ~SceneObject();

      void SetTransformationMatrix(const glm::mat4x4 mat);
      glm::mat4 getTransformationMatrix() const;

    private:
      glm::mat4 transformationMatrix;
  };
}
