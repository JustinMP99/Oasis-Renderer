#include "../Headers/Graphics.h"

//Core Functions
bool Graphics::Initialize()
{
	//Load OpenGL
	gladLoadGL();

	//Set Viewport size
	glViewport(0, 0, 800, 600);

	//Setup Imgui
	IMGUI_CHECKVERSION();

	//Create Triangle
	CreateTriangle();

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
		glClearColor(0.50f, 0.5f, 0.0f, 1.0f);
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	//Render Triangle
	if (showTriangle)
	{

		glUseProgram(triangleProgram);
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

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
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	return true;
}

bool Graphics::InitializeImGui()
{

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");


	return true;

}

//Additional Functions
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
	glBindVertexArray(VAO);



	//Bind VBO, specifying its a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Fill the buffer data with data from the vertices
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Configure Vertex Attribute Pointer so OpenGL knows how to read the VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Use Shader program
	glUseProgram(triangleProgram);

	//Bind



	return true;
}

bool Graphics::CreateCube()
{
	return true;
}


bool Graphics::RenderGUI()
{

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	RenderInspector();

	RenderAdditionalWindow();

	ImGui::ShowDemoWindow();

	ImGui::Render();

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	return true;

}

bool Graphics::RenderInspector()
{

	ImGui::Begin("Scene Inspector");

	ImGui::Text("Control testing values here");

	ImGui::Checkbox("Show Background: ", &showBackground);

	ImGui::Checkbox("Show Triangle: ", &showTriangle);

	ImGui::End();

	return true;
	
}

bool Graphics::RenderAdditionalWindow()
{

	ImGui::Begin("Another Window");   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	ImGui::Text("Hello from another window!");
	ImGui::End();

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