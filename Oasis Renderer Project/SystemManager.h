#pragma once
#include <iostream>

#include "SystemGlobals.h"
#include "Graphics.h"
#include "WindowManager.h"

class SystemManager
{

private:

	Graphics* renderer;
	WindowManager* WinManager;



public:

	bool Initialize();

	bool ProgramLoop();

	bool Shutdown();

};

