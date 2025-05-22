cmake_minimum_required(VERSION 3.10.0)
project(OpenGLRenderer VERSION 0.0.1 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)

add_executable(OpenGLRenderer 
Core/Main.cpp
Source/Source/SystemManager.cpp
Source/Source/GameObject.cpp
Source/Source/Graphics.cpp
Source/Source/Material.cpp
Source/Source/Vertex.cpp
Source/Source/WindowManager.cpp
Source/Source/glad.c
)

# Set GLFW include and lib paths
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/GLFW")
set(GLAD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/glad")
set(KHR_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/KHR")

set(IMGUI_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/imgui")
set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/Additional/Library/glfw3.lib")

# Include GLFW headers
include_directories(${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR} ${IMGUI_INCLUDE_DIR} ${KHR_INCLUDE_DIR})

# Link GLFW and OpenGL
target_link_libraries(OpenGLRenderer PRIVATE ${GLFW_LIBRARY} ${OPENGL_gl_LIBRARY} )


