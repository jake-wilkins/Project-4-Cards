#version 330 core

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec2 texPosition;

out vec2 out_texPosition;

void main()
{
	gl_Position = vPosition;
	out_texPosition = texPosition;
}
