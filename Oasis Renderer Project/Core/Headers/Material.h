#pragma once
#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string GetFileContents(const char* filename);

class Material
{

private:



public:

	unsigned int program;

	//Constructor for the Material object
	Material(const char* vertexPath, const char* fragmentPath);

	//Sets the shader to be active
	void Use();

	//Utility uniform functions
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

};