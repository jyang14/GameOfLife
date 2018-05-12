#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 normals;
layout (location = 2) in vec2 tex_coord;
layout (location = 3) in mat4 model_instance;
layout (location = 7) in uint display;

out vec2 TexCoord;
out float Display;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view  * model_instance * vec4(pos, 1.0f);
	TexCoord = vec2(tex_coord.x, tex_coord.y);
    Display = float(display);
}