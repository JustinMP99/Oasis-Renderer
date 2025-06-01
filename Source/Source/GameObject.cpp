#include "../Headers/GameObject.h"


GameObject::GameObject()
{

}

GameObject::~GameObject()
{
	
	delete mesh;
	delete material;

}


void GameObject::Draw()
{

	//Use Material
	material->Use();

	//Bind Mesh VAO & call Draw Elements
	mesh->Use();

}
