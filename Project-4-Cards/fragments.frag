#version 330 core

uniform sampler2D tex;
uniform vec4 Ambient;
in vec2 out_texPosition;

out vec4 color;

void main()
{
	vec4 scatteredLight = Ambient;
	//sets thelightto be the minimum of the texture modified by the ambient light
	//and 1.0, which is pure white.
	color = min(out_texPosition*scatteredLight, vec4(1.0))
	//color = vec4(0.0, 1.0, 0.0, 1.0);
	//color = max( texture(tex, out_texPosition), 0.2 ) ;
}
