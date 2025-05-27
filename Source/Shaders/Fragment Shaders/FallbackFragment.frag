
#version 330 core
  
//in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord;

out vec4 FragColor;

uniform vec4 col;
uniform sampler2D ourTexture;

void main()
{
   
    FragColor = texture(ourTexture, texCoord);

} 

