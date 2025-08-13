#pragma once
#include "../SystemGlobals.h"
#include <glfw3.h>


///
/// Handles the creation and managment of the window
///
class WindowManager
{
private:

	char windowTitle[240]; /* the title of the window */
	GLFWwindow* mainWindow = NULL; /* pointer to the GLFW window*/
	int windowHeight;
	int windowWidth;

#define WINDOW_METHOD GLFW

public:


	bool Initialize();

	/// Frees all memory taken up by the window
	bool Shutdown();

	//Getter
	int GetWindowWidth();

	int GetWindowHeight();

	GLFWwindow* GetGLFWWindow();

	//Setter
	void SetWindowWidth(int newWidth);

	void SetWindowHeight(int newHeight);
};
