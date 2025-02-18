#include "../Headers/WindowManager.h"

//PRIVATE

//PUBLIC

bool WindowManager::Initialize()
{
	//Create Window

	//Initialize GLFW library
	glfwInit();

	//Set OpenGL version major
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	//Set OpenGL version minor
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Set Window Transparent
	//glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);

	//Set the OpenGL profile to Core (Not Compatibility)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	strcpy_s(windowTitle, "Oasis Renderer");

	//Check Graphics API
	if (GRAPHICS_API == OPENGL)
	{
		const char temp[] = " - OpenGL";
		strcat_s(windowTitle, temp);
	}
	else if (GRAPHICS_API == DIRECTX11)
	{
		const char temp[] = " - DirectX 11";
		strcat_s(windowTitle, temp);
	}

	//Check Window Method
	if (WINDOW_METHOD == GLFW)
	{
		const char temp[] = " - GLFW ";
		strcat_s(windowTitle, temp);
	}
	else if (WINDOW_METHOD == NATIVE)
	{
		const char temp[] = " - Native ";
		strcat_s(windowTitle, temp);
	}

	mainWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);

	if (mainWindow == NULL)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(mainWindow);

	return true;
}

bool WindowManager::Shutdown()
{
	return true;
}

#pragma region Getter

int WindowManager::GetWindowWidth()
{
	return windowWidth;
}

int WindowManager::GetWindowHeight()
{
	return windowHeight;
}

GLFWwindow* WindowManager::GetGLFWWindow()
{
	return mainWindow;
}

#pragma endregion

#pragma region Setter

void WindowManager::SetWindowWidth(int newWidth)
{
	windowWidth = newWidth;
}

void WindowManager::SetWindowHeight(int newHeight)
{
	windowHeight = newHeight;
}

#pragma endregion