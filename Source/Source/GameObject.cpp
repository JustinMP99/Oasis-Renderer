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


void GameObject::Draw()
{

	//Use Material
	material->Use();

	//Bind Mesh VAO & call Draw Elements
	mesh->Use();

}
