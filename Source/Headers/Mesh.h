#pragma once
#include "../SystemGlobals.h"
#include "Vertex.h"
#include <vector>


class Mesh
{

private:

	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;

	void SetupMesh();

public:


	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	Mesh();
	Mesh(std::vector<Vertex> newVertices, std::vector<unsigned int> indices);

	~Mesh();

	/// <summary>
	/// Binds VAO & calls DrawElements
	/// </summary>
	void Use();

};