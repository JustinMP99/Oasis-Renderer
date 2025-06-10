#include "../Headers/Material.h"


std::string GetFileContents(const char* filename)
{

	std::string result = "";
	std::string line = "";
	std::ifstream in(filename);

	if (in.is_open())
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);

	}

	throw(errno);

}

//Constructors
Material::Material() {}

Material::Material(unsigned int vertexShader, unsigned int fragmentShader)
{
	SetShaders(vertexShader, fragmentShader);
}

Material::Material(unsigned int vertexShader, unsigned int fragmentShader, unsigned int mainTexture)
{

	//SetShaders(vertexShader, fragmentShader);

	SetMainTexture(mainTexture);

}

//Destructors
Material::~Material()
{

}

void Material::Use()
{

	//Bind Texture
	glBindTexture(GL_TEXTURE_2D, mainTexture);
	
	//Use Shader Program
	glUseProgram(program);

}

//Getters
bool Material::GetCompletionStatus()
{
	return completed;
}

//Setters

/// <summary>
/// Sets the Materials name
/// </summary>
/// <param name="name">Name to be set</param>
/// <returns></returns>
bool Material::SetMaterialName(const char* name)
{
	materialName = std::string(name);

	return true;
}

/// <summary>
/// Links the passed in shaders to this Materials shader program
/// </summary>
/// <param name="vertexShader">Vertex shader to link</param>
/// <param name="fragmentShader">Fragment shader to link</param>
/// <returns></returns>
bool Material::SetShaders(unsigned int vertexShader, unsigned int fragmentShader)
{

	int success;
	char infoLog[512];

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
			infoLog << std::endl;
	}
	//deleteshaders;they�relinkedintoourprogramandnolongernecessary
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return true;
}

/// <summary>
/// Sets the main texture of the Material
/// </summary>
/// <param name="mainTexture">Texture to set</param>
/// <returns></returns>
bool Material::SetMainTexture(unsigned int newMainTexture)
{

	mainTexture = newMainTexture;
	return true;

}

void Material::SetBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value);
}

void Material::SetInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Material::SetFloat(const std::string& name, float value) const
{
	glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

