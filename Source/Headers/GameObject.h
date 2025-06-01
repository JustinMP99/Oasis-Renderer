
#pragma once
#include <glad.h>
#include "Vertex.h"
#include "Material.h"
#include "Mesh.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"


class GameObject
{

private:

public:

	//Position
	glm::mat4 model = glm::mat4(1.0f);

	//Material Variables
	Material* material;
	Mesh* mesh;
	
	GameObject();
	~GameObject();

	void Draw();

};
