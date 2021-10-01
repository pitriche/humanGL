#version 410 core

uniform int		color;	/* temporary */ /* definitely not temporary lol */

uniform mat4	matrix_model;
uniform mat4	matrix_view;
uniform mat4	matrix_proj;

layout (location = 0) in vec3	position_vertex;

out vec3		color_vertex;
out vec3		pos_vertex;		/* clip space position to compute normal */

void	main(void)
{
	vec4	tmp_pos;

	color_vertex = vec3(((color >> 16) & 0xff) / 255.0f,
		((color >> 8) & 0xff) / 255.0f,
		(color & 0xff) / 255.0f);

	tmp_pos = matrix_view * matrix_model * vec4(position_vertex, 1);
	pos_vertex = tmp_pos.xyz;
	tmp_pos.x /= (16.0 / 9.0);	/* screen ratio */
	gl_Position = vec4(tmp_pos.xy, -1, tmp_pos.z);
}


