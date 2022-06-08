#version 330 core

out vec4 FragColor;

//uniform vec3 u_lightcolor;
//unifrom ve3 u_darkcolor;

void main()
{
	float lerp = 0.5f;
	//vec3 color = mix(u_lightcolor,u_darkcolor,lerp);
	FragColor = vec4(0.8f,0.3f,0.4f, 1.0f);
}