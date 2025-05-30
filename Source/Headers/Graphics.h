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

	//Shaders 

#pragma region Data Paths

#if PLATFORM == WINDOWS

	//Shader

	//Desktop
	const char* fallbackVertexShaderPath = "D:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Path to Fallback Vertex Shader
	const char* fallbackFragmentShaderPath = "D:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag";

	//Laptop
	//const char* fallbackVertexShaderPath = "G:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert"; //Laptop Path
	//const char* fallbackFragmentShaderPath = "G:/Projects/Graphics/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag"; //Laptop Path

	//Textures
	//Desktop
	const char* testTexturePath = "D:/Projects/Graphics/Oasis-Renderer/Additional/Images/container.jpg";

	//Laptop
	//const char* testTexturePath = "G:/Projects/Graphics/Oasis-Renderer/Additional/Images/container.jpg";

#elif PLATFORM == MACOS

	//Shader 
	const char* fallbackVertexShaderPath = "/Users/justinphilie/Documents/Graphics Projects/Oasis-Renderer/Source/Shaders/Vertex Shaders/FallbackVertex.vert";
	const char* fallbackFragmentShaderPath = "/Users/justinphilie/Documents/Graphics Projects/Oasis-Renderer/Source/Shaders/Fragment Shaders/FallbackFragment.frag";

	//Texture
	const char* testTexturePath = "/Users/justinphilie/Documents/Graphics Projects/Oasis-Renderer/Additional/Images/container.jpg";


#endif

#pragma endregion

	//Textures
	unsigned int* containerTexture;

	//Shaders
	unsigned int* fallbackVertexShader;
	unsigned int* fallbackFragmentShader;

	//Materials
	Material* fallbackMat;

public:


#pragma region Constructors

	Graphics();

#pragma endregion

#pragma region Destructors

	~Graphics();

#pragma endregion


	//Core Functions
#pragma region Core Functions

	bool Initialize();

	bool Render();

	bool Shutdown();

#pragma endregion

#pragma region UI Functions (ImGui)

	bool InitializeImGui();

	bool RenderGUI();

	bool RenderInspector();

	bool RenderAdditionalWindow();

	bool InitializeDockspace();

#pragma endregion

	//Helper Functions
#pragma region Material Functions

	bool InitializeMaterial();

	//Additional Functions
	Material CompileMaterial();

#pragma endregion

#pragma region Shader Functions

	bool InitializeShaders();

	unsigned int* CompileVertexShader(const char* filepath);

	unsigned int* CompileFragmentShader(const char* filepath);

#pragma endregion

#pragma region Texture Functions

	bool InitializeTextures();

	unsigned int* CreateTexture(const char* filepath);

#pragma endregion

#pragma region Object Creation Functions


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

#pragma endregion

#pragma region Getter Functions

	std::string getexepath();

#pragma endregion

#pragma region Setter Functions

	//Setter
	void SetMainWindow(GLFWwindow* window);


#pragma endregion

	const char ReadImageFile(const char* filepath);

};
