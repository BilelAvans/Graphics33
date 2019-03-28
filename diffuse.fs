#version 330
uniform vec3  lightPos;  
uniform float time;

in vec3 pos;
in vec3 FragPos;
in vec3 Normal;

in float lightFactor;

out vec4 FragColor;

void main(){
	
	vec3 lightColor = vec3(1,1,1);

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);  

	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	float newTime = time;

	while (newTime > 1){
		newTime = newTime/10;
	}

	float ambientStrength = 0;
    vec3 ambient = ambientStrength * lightColor;

	vec3 result = (ambient + diffuse) * pos;
	FragColor = vec4(result, 1.0);
	
}