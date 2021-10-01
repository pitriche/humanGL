#version 410 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec3		pos_vertex[];
in vec3		color_vertex[];

out vec3	color_geometry;

uniform vec3	camera_pos;

/* ########################################################################## */

vec3	normal(vec3 p1, vec3 p2, vec3 p3)
{
	vec3	v1;
	vec3	v2;

	v1 = p2 - p1;
	v2 = p3 - p1;
	return (normalize(cross(v1, v2)));
}

void	main()
{
	vec3	normal_vec;
	float	mult;
	vec3	color;
	
	normal_vec = normal(pos_vertex[0], pos_vertex[1], pos_vertex[2]);
	mult = abs(dot(normal_vec, vec3(0, 0, 1)));
	color = color_vertex[0] * ((mult + 1) / 2);

	gl_Position = gl_in[0].gl_Position;
	color_geometry = color;
	EmitVertex();

	gl_Position = gl_in[1].gl_Position;
	color_geometry = color;
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;
	color_geometry = color;
	EmitVertex();


	EndPrimitive();
}