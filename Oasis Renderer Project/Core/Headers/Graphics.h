#pragma once
#include "../../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include "../Includes/glad/glad.h"
#endif

#include <GLFW\glfw3.h>

#include "GameObject.h"

class Graphics
{

private:

	GLFWwindow* mainWindow;

	

public:

	//Core Functions

	bool Initialize();

	bool Render();

	bool Shutdown();

	//Additional Functions

	bool CreateCube();

	//Getter


	//Setter
	void SetMainWindow(GLFWwindow* window);
};

