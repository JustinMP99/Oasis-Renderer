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

public:

	//Core Functions

	bool Initialize();

	bool Render();

	bool Shutdown();

	//Additional Functions

	bool CreateCube();

	bool RenderTestingWindow();

	//Getter

	//Setter
	void SetMainWindow(GLFWwindow* window);

	Graphics() = default;
};
