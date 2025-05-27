#pragma once
#include "../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include <glad.h>
#endif

//#include <imgui.h>
//#include <imgui_impl_opengl3.h>
//#include <imgui_impl_glfw.h>
#include <glfw3.h>

#include "GameObject.h"
#include "stb_image.h"

#include <iostream>

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

	//Shader Paths & Materials
#pragma region Shader Paths

	//Desktop
	//const char* fallbackVertexShaderPath = "D:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Path to Fallback Vertex Shader
	//const char* fallbackFragmentShaderPath = "D:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag";

	//Laptop
	//const char* fallbackVertexShaderPath = "G:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Laptop Path
	//const char* fallbackFragmentShaderPath = "G:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag"; //Laptop Path

	//Macbook
	const char* fallbackVertexShaderPath = "/Users/justinphilie/Documents/Graphics Projects/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Laptop Path
	const char* fallbackFragmentShaderPath = "/Users/justinphilie/Documents/Graphics Projects/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag"; //Laptop Path


#pragma endregion


	Material* fallbackMat;

	//Texture Paths
#pragma region Texture Paths

	//Desktop
	//const char* testTexturePath = "D:/Projects/Graphics/Oasis-Renderer/Additional/Images/container.jpg";

	//Laptop
	//const char* testTexturePath = "G:/Projects/Graphics/Oasis-Renderer/Additional/Images/container.jpg";

	//Macbook
	const char* testTexturePath = "/Users/justinphilie/Documents/Graphics Projects/Oasis-Renderer/Additional/Images/container.jpg";


#pragma endregion

	
	//const char* testTexturePath = "goku.png";


	int textureWidth;
	int textureHeight;
	int nrChannels;

	
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
	bool CompileFallbackShaders();

	bool CreateTriangleGameobject();

	bool CreateCube();

	const char ReadImageFile(const char* filepath);

	//Getter

	//Setter
	void SetMainWindow(GLFWwindow* window);

	Graphics() = default;

};
