
#pragma once
#include "../Includes/glad/glad.h"
//#include "../DataTypes/Vertex.h"
#include "../../Vertex.h"


class GameObject
{

private:



public:


	//Mesh Variables
	Vertex* vertices;
	unsigned int* indices;
	GLuint* VBO; //Holds ID to Vertex Buffer
	GLuint* EBO; //Holds ID to Index Buffer
	GLuint* VAO; //Holds ID to Vertex Array 


	//Material Variables
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

	GameObject();
	~GameObject();


};
