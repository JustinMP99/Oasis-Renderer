#pragma once
#include <glad.h> // include glad to get all the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "stb_image.h"


/// <summary>
/// Reads the file passed in and returns its contents as a string
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
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
	
	/// <summary>
	/// Basic Constructor
	/// </summary>
	Material();

	/// <summary>
	/// Constructor that takes the passed in shaders and links them to the program
	/// </summary>
	Material(unsigned int vertexShader, unsigned int fragmentShader);

	/// <summary>
	/// Constructor that takes in vertex and fragment shaders along with a OpenGL texture and assigns them to variables in the Material
	/// </summary>
	Material(unsigned int vertexShader, unsigned int fragmentShader, unsigned int mainTexture);

	//Destructor
	~Material();

	/// <summary>
	/// Sets the program, textures, etc. to be used during rendering
	/// </summary>
	void Use();

	//Getters
	bool GetCompletionStatus();

	//Setters
	bool SetMaterialName(const char* name);
	bool SetShaders(unsigned int vertexShader, unsigned int fragmentShader);
	bool SetMainTexture(unsigned int newMainTexture);
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;

};