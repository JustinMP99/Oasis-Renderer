#pragma once
#include "../SystemGlobals.h"
#include <glfw3.h>



class WindowManager
{
private:

	char windowTitle[240];
	GLFWwindow* mainWindow = NULL;
	int windowHeight;
	int windowWidth;

#define WINDOW_METHOD GLFW

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
