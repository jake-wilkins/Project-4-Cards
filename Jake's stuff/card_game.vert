#version 330 core

layout(location = 0) in vec4 postion;
layout(location = 1) in vec2 tex_coord;

uniform mat4 MVPMatrix;

out vec2 vs_tex_coord;

void main()
{
	gl_Position = MVPMatrix * position;
	vs_tex_coord = tex_coord;
}
