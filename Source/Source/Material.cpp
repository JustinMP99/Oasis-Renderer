#include "../Headers/Material.h"

/// <summary>
/// Reads the file passed in and returns its contents as a string
/// </summary>
/// <param name="filename"></param>
/// <returns></returns>
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


#pragma region Constructors

Material::Material() {}

Material::Material(unsigned int vertexShader, unsigned int fragmentShader)
{
	SetShaders(vertexShader, fragmentShader);
}

Material::Material(unsigned int vertexShader, unsigned int fragmentShader, unsigned int mainTexture)
{

	SetShaders(vertexShader, fragmentShader);

	SetMainTexture(mainTexture);

}


#pragma endregion

void Material::Use()
{

	//Bind Texture
	glBindTexture(GL_TEXTURE_2D, mainTexture);
	
	//Use Shader Program
	glUseProgram(program);

}

#pragma region Getter Functions

bool Material::GetCompletionStatus()
{
	return completed;
}

#pragma endregion

#pragma region Setter Functions

bool Material::SetMaterialName(const char* name)
{
	materialName = std::string(name);

	return true;
}

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
	//deleteshaders;they’relinkedintoourprogramandnolongernecessary
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	return true;
}

bool Material::SetMainTexture(unsigned int mainTexture)
{


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

#pragma endregion

