#include "../Headers/SystemManager.h"

#pragma region Private 


#pragma endregion


#pragma region Public

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

bool SystemManager::Initialize()
{

	std::cout << "Initializing..." << std::endl;

	// Create Window Manager
	WinManager = new WindowManager();

	//Set WinManager data
	WinManager->SetWindowWidth(800);
	WinManager->SetWindowHeight(600);

	//Call WinManager Initialize
	WinManager->Initialize();



	//Create Renderer
	renderer = new Graphics();

	//Set Window
	mainWindow = WinManager->GetGLFWWindow();
	
	//Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to Initialize GLAD!" << std::endl;
		return false;
	}

	//Setup gl viewport
	glViewport(0, 0, WinManager->GetWindowWidth(), WinManager->GetWindowHeight());

	//Set framebuffer callback function
	glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);

	return true;

}

bool SystemManager::ProgramLoop()
{

	while (!glfwWindowShouldClose(mainWindow))
	{
		glfwSwapBuffers(mainWindow);
		glfwPollEvents();
	}


	return true;
}


bool SystemManager::Shutdown()
{

	glfwTerminate();

	//Release Renderer
	renderer->Shutdown();
	delete renderer;

	//Release Window Manager
	WinManager->Shutdown();
	delete WinManager;

	return true;
}




#pragma endregion



