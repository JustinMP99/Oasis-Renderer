#include "../Headers/Graphics.h"

//Core Functions
bool Graphics::Initialize()
{
	
	//Set Viewport size
	glViewport(0, 0, 800, 600);


	return true;

}

bool Graphics::Render()
{


	return true;

}

bool Graphics::Shutdown()
{ 

	return true;

}

//Additional Functions
bool Graphics::CreateCube()
{


	return true;
}


#pragma region Getter

#pragma endregion

#pragma region Setter

void Graphics::SetMainWindow(GLFWwindow* window)
{
	mainWindow = window;
}


#pragma endregion


