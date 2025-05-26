
#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord;

uniform vec4 col;
uniform sampler2D ourTexture;

void main()
{
    //FragColor = vec4(1.0f, 0.5f, 0.5f, 1.0f) + col;
    FragColor = texture(ourTexture, texCoord);
    //FragColor = col;
} 

