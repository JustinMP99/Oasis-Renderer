
#version 330 core

//Data layout
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

//Output variable
out vec2 texCoord;

//variable that can be set outside the shader
uniform mat4 transform;

void main()
{

	//Set vertex position based on passed in transform
	gl_Position = transform * vec4(aPos, 1.0f);

	//set texture coordinate
	texCoord = aTexCoord;

}


