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

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(mainWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	return true;
}

bool Graphics::Render()
{

	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Clear to specific Color
	if (showColor)
	{
		glClearColor(0.75f, 0.5f, 0.0f, 1.0f);
	}
	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
	
	//ImGui
	RenderTestingWindow();

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

//Additional Functions
bool Graphics::CreateTriangle()
{

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
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		
	}

	//Create Fragment Shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	glCompileShader(fragmentShader);


	return true;
}

bool Graphics::CreateCube()
{
	return true;
}

bool Graphics::RenderTestingWindow()
{

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Testing Values");

	ImGui::Text("Control testing values here");

	ImGui::Checkbox("Show Color: ", &showColor);

	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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