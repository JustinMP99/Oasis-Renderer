
#pragma once

class GameObject
{

private:



public:


	//Mesh Variables
	float *vertices[1] = {};
	float *indices[1] = {};
	unsigned int* VBO; //Holds ID to Vertex Buffer
	unsigned int* EBO; //Holds ID to Index Buffer
	unsigned int* VAO; //Holds ID to Vertex Array 


	//Material Variables
	unsigned int* vertexShader;
	unsigned int* fragmentShader;
	unsigned int shaderProgram;

	GameObject();


};
