#pragma once
#include "../SystemGlobals.h"

#if GRAPHICS_API == OPENGL
#include <glad.h>
#endif

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"


struct Vertex
{
	
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uv;

};