#version 330 core

uniform sampler2D tex;

in vec2 out_texPosition;

out vec4 color;

void main()
{
	color = vec4(0.0, 1.0, 0.0, 1.0);
	//color = max( texture(tex, out_texPosition), 0.2 ) ;
}
