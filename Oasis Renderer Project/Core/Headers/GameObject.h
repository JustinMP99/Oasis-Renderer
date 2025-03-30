
#pragma once
#include <vector>


class GameObject
{

private:



public:
	
	std::vector<float> vertices;
	std::vector<int> indices;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;
	unsigned int shaderProgram;

};
