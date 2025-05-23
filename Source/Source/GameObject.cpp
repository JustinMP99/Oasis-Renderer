#include "../Headers/GameObject.h"


GameObject::GameObject()
{

	VAO = new GLuint;
	VBO = new GLuint;
	EBO = new GLuint;

}

GameObject::~GameObject()
{

	delete VAO;
	delete VBO;
	delete EBO;

}
