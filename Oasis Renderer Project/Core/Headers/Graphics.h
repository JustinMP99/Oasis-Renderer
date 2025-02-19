#pragma once
#include "../../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include "../Includes/glad/glad.h"
#endif

#include "Imgui/imgui.h"
#include "imgui\imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include <GLFW\glfw3.h>

#include "GameObject.h"

class Graphics
{
private:

	GLFWwindow* mainWindow;

	bool showColor = true;

	//Triangle Variables
	float vertices[9] = {
	
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f, 0.5f, 0.0f

	};

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
		"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";

	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int VBO;
	

public:

	//Core Functions

	bool Initialize();

	bool Render();

	bool Shutdown();

	//Additional Functions
	
	bool CreateTriangle();

	bool CreateCube();

	bool RenderTestingWindow();

	//Getter

	//Setter
	void SetMainWindow(GLFWwindow* window);

	Graphics() = default;
};
