#include "../Core/Headers/SystemManager.h"

int main()
{
	SystemManager* system = new SystemManager();

	system->Initialize();

	system->ProgramLoop();

	system->Shutdown();

	return 0;
}