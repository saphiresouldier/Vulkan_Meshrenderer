cmake_minimum_required(VERSION 3.8)
project(VulkanMeshRenderer VERSION 0.1)

#add_subdirectory("${PROJECT_SOURCE_DIR}/source")
#add_subdirectory("${PROJECT_SOURCE_DIR}/header")

set(ENABLE_BENCHMARK          TRUE  CACHE BOOL "enable benchmarking")
set(ENABLE_MEMORY_TRACKING    TRUE  CACHE BOOL "enable memory tracking")

#include(sources.cmake)

include_directories(include)
set(INCLUDES
  ${INCLUDES}
  include/RenderEngine.h
  include/Scene.h
  include/SceneObject.h
  include/ViewerApplication.h
  include/VulkanBase.h
  include/WindowingSystem.h
)

set(SOURCES
  ${SOURCES}
  source/main.cpp
  source/RenderEngine.cpp
  source/Scene.cpp
  source/SceneObject.cpp
  source/ViewerApplication.cpp
  source/VulkanBase.cpp
  source/WindowingSystem.cpp
)

include_directories("${PROJECT_SOURCE_DIR}/external")

# vulkan
find_package(Vulkan REQUIRED)
if(NOT Vulkan_FOUND)
  message(ERROR " Vulkan not found!")
endif(NOT Vulkan_FOUND)
set(LIBRARIES
    ${LIBRARIES}
    Vulkan::Vulkan
)

# GLFW
set(GLFW_DIR "${PROJECT_SOURCE_DIR}/submodule/glfw")
add_subdirectory("${GLFW_DIR}")
include_directories("${GLFW_DIR}/include")
set(LIBRARIES
    ${LIBRARIES}
    glfw
    ${GLFW_LIBRARIES}
)

# glm
set(GLM_DIR "${PROJECT_SOURCE_DIR}/submodule/glm")
add_subdirectory("${GLM_DIR}")
include_directories("${GLM_DIR}")

#add_definitions(-D_BENCHMARK)

if (WIN32)
  add_definitions(-DVK_USE_PLATFORM_WIN32_KHR)
elseif(APPLE)
  add_definitions(-DVK_USE_PLATFORM_MACOS_MVK)
elseif(UNIX)
  add_definitions(-DVK_USE_PLATFORM_XCB_KHR)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  # multicore compilation
  add_definitions(/MP)
  # allow to create huge obj files
  add_definitions(/bigobj)
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)