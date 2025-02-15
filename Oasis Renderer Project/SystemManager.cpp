#include "SystemManager.h"

#pragma region Private 


#pragma endregion


#pragma region Public


bool SystemManager::Initialize()
{

	std::cout << "Initializing..." << std::endl;

	return true;

}

bool SystemManager::ProgramLoop()
{


	return true;
}


bool SystemManager::Shutdown()
{

	//Release Renderer
	renderer->Shutdown();
	delete renderer;

	//Release Window Manager
	WinManager->Shutdown();
	delete WinManager;

	return true;
}


#pragma endregion



