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

#ImGui
#Additional/Includes/imgui/imgui.cpp
#Additional/Includes/imgui/imgui_draw.cpp
#Additional/Includes/imgui/imgui_impl_glfw.cpp
#Additional/Includes/imgui/imgui_impl_opengl3.cpp
#Additional/Includes/imgui/imgui_tables.cpp
#Additional/Includes/imgui/imgui_widgets.cpp

)

# Set GLFW include and lib paths
set(GLAD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/glad")
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/GLFW")
set(KHR_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/KHR")

set(IMGUI_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/imgui")
set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/Additional/Library/glfw3.lib")


# Include GLFW headers
target_include_directories(OpenGLRenderer PRIVATE
	${GLAD_INCLUDE_DIR} 
	${GLFW_INCLUDE_DIR} 
	#${IMGUI_INCLUDE_DIR} 
	${KHR_INCLUDE_DIR}
)

# Link GLFW and OpenGL
target_link_libraries(OpenGLRenderer PRIVATE 

${GLFW_LIBRARY} 
${OPENGL_gl_LIBRARY} 

)


