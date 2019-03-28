#version 330
layout(location=0) in vec3 a_position;
layout(location=1) in vec3 a_color;
layout(location=2) in vec2 a_texcoord;
layout(location=3) in vec3 a_normal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

out vec3 Normal;
out vec3 FragPos;
out vec3 pos;


out float lightFactor;

void main()
{
	  vec3 eyeNormal = normalize(normalMatrix*a_normal);
	  vec3 lightPosition = vec3(0,0,1);
	  lightFactor = max(0.0, dot(eyeNormal, normalize(lightPosition)));


    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(a_position, 1.0);
	FragPos = vec3(modelMatrix * vec4(a_position, 1.0));
    Normal = a_normal;
	pos = a_position;
} 