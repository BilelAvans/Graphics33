#version 330
uniform sampler2D s_texture;
varying vec2 texCoord;
varying vec3 color;
uniform float time;


void main()
{
	gl_FragColor = vec4(1,1,1,1);
}