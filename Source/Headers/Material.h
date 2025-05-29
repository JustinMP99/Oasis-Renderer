#pragma once
#include <glad.h> // include glad to get all the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "stb_image.h"

std::string GetFileContents(const char* filename);

class Material
{

private:

	bool completed; //Set if the Material has be successfully Created

public:

	std::string materialName;
	unsigned int program;
	unsigned int mainTexture;

	//Constructor for the Material object
	Material();
	Material(unsigned int* vertexShader, unsigned int* fragmentShader);
	Material(unsigned int* vertexShader, unsigned int* fragmentShader, const char* mainTexturePath);
	Material(unsigned int vertexShader, unsigned int fragmentShader);

	//Setup Functions

	/// <summary>
	/// Sets the program, textures, etc. to be used during rendering
	/// </summary>
	void Use();

#pragma region Getter Functions

	bool GetCompletionStatus();

#pragma endregion

#pragma region Setter Functions

	bool SetMaterialName(const char* name);
	bool SetShaders(unsigned int* vertexShader, unsigned int* fragmentShader);
	bool SetMainTexture(const char* texturePath);
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

#pragma endregion

};