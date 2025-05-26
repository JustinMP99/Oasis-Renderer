#pragma once
#include "../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include <glad.h>
#endif


class UV
{


private:


public:

	GLfloat U; //X position on UV Coordinates
	GLfloat V; //Y position on UV Coordinates


	UV();
	UV(GLfloat u, GLfloat v);
	~UV();

};