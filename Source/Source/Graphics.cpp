#include "../Headers/Graphics.h"

//Core Functions
bool Graphics::Initialize()
{
	//Load OpenGL
	gladLoadGL();

	//Set Viewport size
	glViewport(0, 0, 800, 600);

	//Setup Imgui
	//IMGUI_CHECKVERSION();

	

	//Compile all shaders
	CompileFallbackShaders();

	//Create Triangle Game Object
	//CreateTriangleGameobject();

	//Create Square
	CreateCube();

	//Initialize ImGui
	InitializeImGui();

	return true;
}

bool Graphics::Render()
{

	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Clear to specific Color
	if (showBackground)
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	for (int i = 0; i < sceneObjects.size(); i++)
	{

		sceneObjects[i]->material->Use();

		glBindVertexArray(*sceneObjects[i]->VAO);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

	}

	//ImGui
	RenderGUI();

	//Swap buffer
	glfwSwapBuffers(mainWindow);

	return true;
}

bool Graphics::Shutdown()
{

	//Shutdown ImGui
	//ImGui_ImplOpenGL3_Shutdown();
	//ImGui_ImplGlfw_Shutdown();
	//ImGui::DestroyContext();

	//Destroy all GameObjects
	for (int i = 0; i < sceneObjects.size(); i++)
	{
		
		delete sceneObjects[i];
	}

	return true;
}

#pragma region ImGui Functions

bool Graphics::InitializeImGui()
{

	//ImGui::CreateContext();
	//ImGuiIO& io = ImGui::GetIO(); (void)io;
	//ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	//ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	//ImGui::StyleColorsDark();
	//ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
	//ImGui_ImplOpenGL3_Init("#version 330");


	return true;

}

bool Graphics::RenderGUI()
{

	/*ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();*/

	//InitializeDockspace();

	RenderInspector();

	RenderAdditionalWindow();

	//ImGui::ShowDemoWindow();

	/*ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}*/


	return true;

}

bool Graphics::InitializeDockspace()
{

	//static bool dockspaceOpen = true;
	//static bool opt_fullscreen_persist = true;
	//bool opt_fullscreen = opt_fullscreen_persist;
	//static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;


	//// Set up fullscreen dockspace
	//ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	//if (opt_fullscreen)
	//{
	//	ImGuiViewport* viewport = ImGui::GetMainViewport();
	//	ImGui::SetNextWindowPos(viewport->WorkPos);
	//	ImGui::SetNextWindowSize(viewport->WorkSize);
	//	ImGui::SetNextWindowViewport(viewport->ID);
	//	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
	//	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	//	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
	//	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	//}

	//// Dockspace window
	//ImGui::Begin("DockSpace", &dockspaceOpen, window_flags);

	//if (opt_fullscreen)
	//	ImGui::PopStyleVar(2);

	//// Submit the DockSpace
	//ImGuiIO& io = ImGui::GetIO();
	//if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	//{
	//	ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
	//	ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	//}

	//ImGui::End();


	return true;
}

bool Graphics::RenderInspector()
{

	//ImGui::Begin("Scene Inspector");

	//ImGui::Text("Control testing values here");

	//ImGui::Checkbox("Show Background: ", &showBackground);

	//ImGui::Checkbox("Show Triangle: ", &showTriangle);

	//ImGui::End();

	return true;

}

bool Graphics::RenderAdditionalWindow()
{

	//ImGui::Begin("Another Window");   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	//ImGui::Text("Hello from another window!");
	//ImGui::End();

	return true;
}


#pragma endregion

bool Graphics::InitializeShaders()
{
	return false;
}

bool Graphics::CompileFallbackShaders()
{

	fallbackMat = new Material(fallbackVertexShaderPath, fallbackFragmentShaderPath);

	if (!fallbackMat->GetCompletionStatus())
	{
		std::cout << "Error Creating Fallback Material" << std::endl;
	}

	return true;
}

//Additional Functions

bool Graphics::CreateTriangleGameobject()
{

	//GameObject* newGameObject = new GameObject();

	////Set Vertex & Index array
	//Vertex tempArr[3] = {

	//	 Vertex(-0.5f, -0.5f, 0.0f),
	//	 Vertex( 0.5f, -0.5f, 0.0f),
	//	 Vertex( 0.0f,  0.5f, 0.0f)

	//};
	//
	//unsigned int tempIndex[3] =
	//{
	//	0, 1, 2
	//};

	//newGameObject->vertices = new Vertex[3];
	//memcpy(newGameObject->vertices, tempArr, 3 * sizeof(Vertex));

	//newGameObject->indices = new unsigned int[3];
	//memcpy(newGameObject->indices, tempIndex, 3 * sizeof(unsigned int));


	//glGenVertexArrays(1, newGameObject->VAO);
	//
	//glBindVertexArray(*newGameObject->VAO);

	////Generate, Bind & Fill VBO
	//glGenBuffers(1, newGameObject->VBO);

	//glBindBuffer(GL_ARRAY_BUFFER, *newGameObject->VBO);

	//glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), newGameObject->vertices, GL_STATIC_DRAW);

	////Generate, Bind & Fill EBO
	//glGenBuffers(1, newGameObject->EBO);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *newGameObject->EBO);

	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), newGameObject->indices, GL_STATIC_DRAW);

	////Set Vertex Attribute Pointers
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

	//glEnableVertexAttribArray(0);

	////Assign Material
	//newGameObject->material = fallbackMat;

	////Add object to list
	//sceneObjects.push_back(newGameObject);

	return true;
}

bool Graphics::CreateCube()
{

	std::cout << "Creating Square..." << std::endl;

	//Create Vertex Array
	//Vertex tempVertArray[4] = {

	//	 Vertex(-0.5f,  0.5f, 0.0f),   //Top Left
	//	 Vertex(0.5f,  0.5f, 0.0f),    //Top Right
	//	 Vertex(-0.5f, -0.5f, 0.0f),   //Bottom Left
	//	 Vertex(0.5f, -0.5f, 0.0f),    //Bottom Right

	//};

	GLfloat tempVertArray[] = {

		//Positions								//Texture Coordinates
		-0.5f,  0.5f, 0.0f,						0.1f, 1.0f,					//Top Left        
		0.5f,  0.5f, 0.0f,						1.0f, 1.0f,					//Top Right
		-0.5f, -0.5f, 0.0f,						0.0f, 0.0f,					//Bottom Left
		0.5f, -0.5f, 0.0f,						1.0f, 0.0f					//Bottom Right

	};

	//Create Index Array
	unsigned int tempIndexArray[6] =
	{
		0, 1, 2,
		1, 3, 2
	};

	//Create UV Array
	//UV tempUVArray[4] = {

	//	UV(0.0f, 1.0f), //Top Left
	//	UV(1.0f, 1.0f), //Top Right
	//	UV(0.0f, 0.0f), //Bottom Left
	//	UV(1.0f, 0.0f)  //Bottom Right

	//};

	GLfloat tempUVArray[8] = {

	   0.0f, 1.0f, //Top Left
	   1.0f, 1.0f, //Top Right
	   0.0f, 0.0f, //Bottom Left
	   1.0f, 0.0f  //Bottom Right

	};

	//Create New GameObject
	GameObject* square = new GameObject();

	//Fill GameObject Vertex & Index Array
	square->vertices = new GLfloat[20];
	memcpy(square->vertices, tempVertArray, 4 * sizeof(GLfloat));

	square->indices = new unsigned int[6];
	memcpy(square->indices, tempIndexArray, 6 * sizeof(unsigned int));

	square->uv = new GLfloat[8];
	memcpy(square->uv, tempUVArray, 8 * sizeof(GLfloat));

	glGenVertexArrays(1, square->VAO);

	glBindVertexArray(*square->VAO);

	//Create GameObject VBO & EBO
	glGenBuffers(1, square->VBO);

	glBindBuffer(GL_ARRAY_BUFFER, *square->VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(tempVertArray), tempVertArray, GL_STATIC_DRAW);

	glGenBuffers(1, square->EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *square->EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tempIndexArray), tempIndexArray, GL_STATIC_DRAW);

	//Set Position Attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);

	glEnableVertexAttribArray(0);

	//Set UV Attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(1);

	//Set Material
	square->material = fallbackMat;

	int colorLocation = glGetUniformLocation(square->material->program, "col");
	square->material->Use();
	glUniform4f(colorLocation, 0.0f, 1.0f, 0.0f, 1.0f);


	//Generate Texture
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	unsigned char* data = stbi_load(testTexturePath, &textureWidth, &textureHeight, &nrChannels, 0);
	if (stbi_failure_reason())
	{
		std::cout << stbi_failure_reason() << std::endl;
	}

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);


	//TEST
	//glActiveTexture(GL_TEXTURE0); // activate the texture unit first before binding texture
	//glBindTexture(GL_TEXTURE_2D, texture);

	sceneObjects.push_back(square);

	return true;
}


const char Graphics::ReadImageFile(const char* filepath)
{

	const char* data;

	std::string line;
	std::string text;

	std::ifstream in(testTexturePath);

	while (std::getline(in, line))
	{
		text += line + "\n";
	}

	data = text.c_str();

	if (data == nullptr)
	{
		std::cout << "Error Reading Image" << std::endl;
	}

	return *data;

}


#pragma region Getter

#pragma endregion

#pragma region Setter

void Graphics::SetMainWindow(GLFWwindow* window)
{
	mainWindow = window;
}

#pragma endregion