#pragma once
#include "../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include <glad.h>
#endif

#if PLATFORM == WINDOWS

#include <windows.h>

#endif

//#include <imgui.h>
//#include <imgui_impl_opengl3.h>
//#include <imgui_impl_glfw.h>
#include <glfw3.h>
#include <iostream>
#include <string>
#include <filesystem>

#include <vector>
#include "GameObject.h"

class Graphics
{
private:

	GLFWwindow* mainWindow;

	std::vector<GameObject*> sceneObjects;

#pragma region Data Paths

#if PLATFORM == WINDOWS

	//Shader

	//Desktop
	//const char* fallbackVertexShaderPath = "D:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Path to Fallback Vertex Shader
	//const char* fallbackFragmentShaderPath = "D:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag";

	//Laptop
	const char* fallbackVertexShaderPath = "G:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Laptop Path
	const char* fallbackFragmentShaderPath = "G:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag"; //Laptop Path

#elif PLATFORM == MACOS

	//Shader 
	const char* fallbackVertexShaderPath = "/Users/justinphilie/Documents/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert";
	const char* fallbackFragmentShaderPath = "/Users/justinphilie/Documents/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag";

#endif

	//Texture Paths
	std::string containerTexturePath = std::string(PROJECT_ROOT) + "/Additional/Images/container.jpg";


#pragma endregion

	//Textures
	unsigned int* containerTexture;

	//Shaders
	unsigned int* fallbackVertexShader;
	unsigned int* fallbackFragmentShader;

	//Materials
	Material* fallbackMat;

public:

	//Constructors
	Graphics();

	//Destructors
	~Graphics();

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

	//Material Functions
	bool InitializeMaterial();

	Material CompileMaterial();

	//Shader Functions
	bool InitializeShaders();

	unsigned int* CompileVertexShader(const char* filepath);

	unsigned int* CompileFragmentShader(const char* filepath);

	//Texture Functions
	bool InitializeTextures();

	unsigned int* CreateTexture(const char* filepath);

	//Object Creation Functions
	bool CreateTriangleGameobject();

	/// <summary>
	/// Creates a 2D Quad
	/// </summary>
	/// <returns>Returns True if Successful</returns>
	bool CreateQuad();

	/// <summary>
	/// Creates an GameObject
	/// </summary>
	/// <param name="filepath">Path to the Object</param>
	/// <returns></returns>
	bool CreateObject(const char* filepath);

	//Getters
	std::string getexepath();

	//Setters
	void SetMainWindow(GLFWwindow* window);

	const char ReadImageFile(const char* filepath);

};
