
#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  

uniform vec4 col;

void main()
{
    FragColor = vec4(0.75f, 0.6f, 0.5f, 1.0f);
    //FragColor = col;
} 

