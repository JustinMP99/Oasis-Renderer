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
	CompileShaders();

	//glLinkProgram(fallbackProgram);

	//Create Triangle Game Object
	CreateTriangleGameobject();

	//Initialize ImGui
	//InitializeImGui();

	return true;
}

bool Graphics::Render()
{

	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Clear to specific Color
	if (showBackground)
	{
		glClearColor(0.50f, 0.5f, 0.0f, 1.0f);
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	if (showTriangle)
	{

		for (int i = 0; i < sceneObjects.size(); i++)
		{
			
			//glUseProgram();
			
			//sceneObjects[i]->material->Use();

			glBindVertexArray(*sceneObjects[i]->VAO);
			
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

			glBindVertexArray(0);

		}

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

//UI Functions (ImGui)
bool Graphics::InitializeImGui()
{

	/*ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");*/


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

bool Graphics::InitializeShaders()
{
	return false;
}

bool Graphics::CompileShaders()
{
	//Create Vertex Shader
	fallbackVertexShader = glCreateShader(GL_VERTEX_SHADER);

	//Attach Source to Shader
	glShaderSource(fallbackVertexShader, 1, &vertexShaderSource, NULL);

	//Compile Vertex Shader
	glCompileShader(fallbackVertexShader);

	int success;
	char infoLog[512];

	glGetShaderiv(fallbackVertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{

		std::cout << "Vertex Shader Failed" << std::endl;
		glGetShaderInfoLog(fallbackVertexShader, 512, NULL, infoLog);

	}

	//Create Fragment Shader
	fallbackFragShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fallbackFragShader, 1, &fragmentShaderSource, NULL);

	glCompileShader(fallbackFragShader);

	glGetShaderiv(fallbackFragShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{

		std::cout << "Fragment Shader Failed" << std::endl;
		glGetShaderInfoLog(fallbackFragShader, 512, NULL, infoLog);

	}

	fallbackProgram = glCreateProgram();

	glAttachShader(fallbackProgram, fallbackVertexShader);
	glAttachShader(fallbackProgram, fallbackFragShader);

	glLinkProgram(fallbackProgram);
	

	return true;
}

//Additional Functions

/// <summary>
/// Creates a Triangle for rendering
/// </summary>
/// <returns>True if successful</returns>
bool Graphics::CreateTriangle()
{

	//Generate VAO
	glGenVertexArrays(1, &VAO);

	//Generate Vertex Buffer
	glGenBuffers(1, &VBO);

	//Bind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Set buffer data 
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Create Vertex Shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//Attach Source to Shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	//Compile Vertex Shader
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{

		std::cout << "Vertex Shader Failed" << std::endl;
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		
	}

	//Create Fragment Shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{

		std::cout << "Fragment Shader Failed" << std::endl;
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

	}

	//Create Shader Program
	triangleProgram = glCreateProgram();

	//Attach Shaders to program
	glAttachShader(triangleProgram, vertexShader);
	glAttachShader(triangleProgram, fragmentShader);

	//Link shaders to program
	glLinkProgram(triangleProgram);

	//Delete shaders (No longer used so they can be deleted)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//Bind VAO
	//glBindVertexArray(VAO);

	//Bind VBO, specifying its a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Fill the buffer data with data from the vertices
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Configure Vertex Attribute Pointer so OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Use Shader program
	//glUseProgram(triangleProgram);

	//Bind



	return true;
}

bool Graphics::CreateTriangleGameobject()
{

	GameObject* newGameObject = new GameObject();

	//Set Vertex & Index array
	Vertex tempArr[3] = {

		 Vertex(-0.5f, -0.5f, 0.0f),
		 Vertex( 0.5f, -0.5f, 0.0f),
		 Vertex( 0.0f,  0.5f, 0.0f)

	};
	
	unsigned int tempIndex[3] =
	{
		0, 1, 2
	};


	newGameObject->vertices = new Vertex[3];
	memcpy(newGameObject->vertices, tempArr, 3 * sizeof(Vertex));

	newGameObject->indices = new unsigned int[3];
	memcpy(newGameObject->indices, tempIndex, 3 * sizeof(unsigned int));


	glGenVertexArrays(1, newGameObject->VAO);
	
	glBindVertexArray(*newGameObject->VAO);

	//Generate, Bind & Fill VBO
	glGenBuffers(1, newGameObject->VBO);

	glBindBuffer(GL_ARRAY_BUFFER, *newGameObject->VBO);

	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), newGameObject->vertices, GL_STATIC_DRAW);

	//Generate, Bind & Fill EBO
	glGenBuffers(1, newGameObject->EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *newGameObject->EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), newGameObject->indices, GL_STATIC_DRAW);

	//Set Vertex Attribute Pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

	glEnableVertexAttribArray(0);

	//Create & Assign Material
	fallbackMat = new Material(fallbackVertexShaderPath, fallbackFragmentShaderPath);

	newGameObject->material = fallbackMat;

	//Create Program and assign shaders
	newGameObject->shaderProgram = glCreateProgram();

	glAttachShader(newGameObject->shaderProgram, fallbackVertexShader);
	glAttachShader(newGameObject->shaderProgram, fallbackFragShader);

	glLinkProgram(newGameObject->shaderProgram);

	//Add object to list
	sceneObjects.push_back(newGameObject);

	return true;
}

bool Graphics::CreateCube()
{
	return true;
}

#pragma region Getter

#pragma endregion

#pragma region Setter

void Graphics::SetMainWindow(GLFWwindow* window)
{
	mainWindow = window;
}

#pragma endregion