#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec2 tex_coord;

out vec2 TexCoord;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

void main()
{
	gl_Position = projection * view  * model * vec4(pos, 1.0f);
	TexCoord = vec2(tex_coord.x, tex_coord.y);
}