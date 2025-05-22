#pragma once
#include <iostream>
#include "../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include <glad.h>
#endif

//#include <imgui.h>
//#include <imgui_impl_opengl3.h>
//#include <imgui_impl_glfw.h>
#include <glfw3.h>

#include "GameObject.h"

//#pragma deprecated(CreateTriaangle())

class Graphics
{
private:

	GLFWwindow* mainWindow;

	bool showBackground = true;
	bool showTriangle = true;

	std::vector<GameObject*> sceneObjects;

	//Triangle Variables
	float vertices[9] = {
	
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f, 0.5f, 0.0f

	};

	const char* fallbackVertexShaderPath = "../Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Path to Fallback Vertex Shader
	const char* fallbackFragmentShaderPath = "G:/Projects/Graphics/Oasis - Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag";
	Material* fallbackMat;

	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	const char* fragmentShaderSource = 
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = vec4(0.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
  
	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int fallbackVertexShader;
	unsigned int fallbackFragShader;
	unsigned int fallbackProgram;

	unsigned int VBO;
	unsigned int VAO;
	unsigned int triangleProgram;
	
public:

	//Core Functions

	bool Initialize();

	bool Render();

	bool Shutdown();

	//UI Functions (ImGui)

	bool InitializeImGui();

	bool RenderGUI();

	bool RenderInspector();

	bool RenderAdditionalWindow();

	bool InitializeDockspace();


	//Helper Functions

	bool InitializeShaders();

	//Additional Functions
	bool CompileShaders();

	bool CreateTriangle();

	bool CreateTriangleGameobject();

	bool CreateCube();

	//Getter

	//Setter
	void SetMainWindow(GLFWwindow* window);

	Graphics() = default;

};
