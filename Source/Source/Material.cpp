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

Material::Material(const char* vertexPath, const char* fragmentPath)
{
	SetShaders(vertexPath, fragmentPath);
}

Material::Material(const char* vertexPath, const char* fragmentPath, const char* mainTexturePath)
{

	SetShaders(vertexPath, fragmentPath);

	SetMainTexture(mainTexturePath);

}

Material::Material(unsigned int vertexShader, unsigned int fragmentShader)
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

}

#pragma endregion

bool Material::SetMaterialName(const char* name)
{
	materialName = *name;

	return true;
}

bool Material::SetShaders(const char* vertexPath, const char* fragmentPath)
{

	////Retrieve the Vertex/Fragment source from the given filepaths
	//std::string vertexCode;
	//std::string fragmentCode;
	//std::ifstream vShaderFile;
	//std::ifstream fShaderFile;

	//vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	//fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	//try
	//{
	//	vShaderFile.open(vertexPath);
	//	fShaderFile.open(fragmentPath);

	//	std::stringstream vShaderStream;
	//	std::stringstream fShaderStream;

	//	vShaderStream << vShaderFile.rdbuf();
	//	fShaderStream << fShaderFile.rdbuf();

	//	vShaderFile.close();
	//	fShaderFile.close();

	//	vertexCode = vShaderStream.str();
	//	fragmentCode = fShaderStream.str();

	//}
	//catch (std::ifstream::failure e)
	//{
	//	std::cout << "Error Reading File from File Path\n" << std::endl;
	//}

	//const char* vShaderCode = vertexCode.c_str();
	//const char* fShaderCode = fragmentCode.c_str();

	////2. Create Shaders
	//unsigned int vertex;
	//unsigned int fragment;


	//vertex = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertex, 1, &vShaderCode, NULL);
	//glCompileShader(vertex);

	////Print Compile Errors if Any
	//glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	//if (!success)
	//{
	//	glGetShaderInfoLog(vertex, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
	//		infoLog << std::endl;
	//};

	//fragment = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragment, 1, &fShaderCode, NULL);
	//glCompileShader(fragment);

	////Print Compile Errors if Any
	//glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	//if (!success)
	//{
	//	glGetShaderInfoLog(fragment, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
	//		infoLog << std::endl;
	//};

	//3. Create Shader Program
	


	return true;
}

bool Material::SetMainTexture(const char* texturePath)
{

	
	return true;

}

void Material::Use()
{

	//Bind Texture
	glBindTexture(GL_TEXTURE_2D, mainTexture);
	
	//Use Shader Program
	glUseProgram(program);

}

bool Material::GetCompletionStatus()
{
	return completed;
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

