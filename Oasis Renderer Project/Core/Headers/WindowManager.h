#pragma once
#include "../../SystemGlobals.h"
#include <GLFW\glfw3.h>

class WindowManager
{
private:

	char windowTitle[240];
	GLFWwindow* mainWindow = NULL;
	int windowHeight;
	int windowWidth;

public:

	bool Initialize();

	bool Shutdown();

	//Getter
	int GetWindowWidth();

	int GetWindowHeight();

	GLFWwindow* GetGLFWWindow();

	//Setter
	void SetWindowWidth(int newWidth);

	void SetWindowHeight(int newHeight);
};
