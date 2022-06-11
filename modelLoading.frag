#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{    
    vec3 vcolor = vec3(1,1,1);
    FragColor = texture(texture_diffuse1, TexCoords)*vec4(vcolor,1);

}