#include "../Headers/SystemManager.h"


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

	//Set Window
	mainWindow = WinManager->GetGLFWWindow();

	//Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to Initialize GLAD!" << std::endl;
		return false;
	}

	//Set framebuffer callback function
	glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);

	//Create Renderer
	renderer = new Graphics();

	//Initialize Renderer
	renderer->SetMainWindow(mainWindow);
	renderer->Initialize();

	return true;
}

bool SystemManager::ProgramLoop()
{
	std::cout << "Starting Program Loop..." << std::endl;

	while (!glfwWindowShouldClose(mainWindow))
	{
		//Process Input

		//Process other information

		//Render
		renderer->Render();

		//glfwSwapBuffers(mainWindow);
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
