#pragma once
#include "../../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include "../Includes/glad/glad.h"
#endif

class Vertex
{

private:


public:

	GLfloat X;
	GLfloat Y;
	GLfloat Z;


	Vertex();

	Vertex(float x, float y, float z);

	~Vertex();

};