#pragma once
#include <iostream>

#include "../SystemGlobals.h"
#include <glad.h>
#include <glfw3.h>
#include "Graphics.h"
#include "WindowManager.h"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class SystemManager
{
private:

	Graphics* renderer;
	WindowManager* WinManager;

	GLFWwindow* mainWindow;

public:

	/// <summary>
	/// Initializes all of the programs starting data such as the window manager, renderer, input handler, etc.
	/// </summary>
	/// <returns></returns>
	bool Initialize();

	bool ProgramLoop();

	bool Shutdown();

};
