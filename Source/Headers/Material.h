#pragma once
#include <glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string GetFileContents(const char* filename);

class Material
{

private:

	bool completed; //Set if the Material has be successfully Created

public:

	char materialName;

	unsigned int program;
	char mainTexture;

	//Constructor for the Material object
	Material();
	Material(const char* vertexPath, const char* fragmentPath);
	Material(const char* vertexPath, const char* fragmentPath, const char* mainTexturePath);

	//Setup Functions
	bool SetMaterialName(const char* name);

	bool SetShaders(const char* vertexPath, const char* fragmentPath);

	bool SetMainTexture(const char* mainTexturePath);

	/// <summary>
	/// Sets the Materials shader program to be active
	/// </summary>
	void Use();

	bool GetCompletionStatus();

	//Utility uniform functions
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

};