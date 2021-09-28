#version 410 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec3		color_vertex[];
in vec3		cam_pos_vertex[];
out vec3	color_geometry;

uniform vec3	camera_pos;

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

	normal_vec = normal(cam_pos_vertex[0], cam_pos_vertex[1],
		cam_pos_vertex[2]);

	mult = abs(dot(normal_vec, cam_pos_vertex[0]));

	gl_Position = gl_in[0].gl_Position;
	color_geometry = color_vertex[0];
	EmitVertex();

	gl_Position = gl_in[1].gl_Position;
	color_geometry = color_vertex[1];
	EmitVertex();

	gl_Position = gl_in[2].gl_Position;
	color_geometry = color_vertex[2];
	EmitVertex();

	// gl_Position = gl_in[3].gl_Position;
	// color_geometry = color_vertex[3];
	// EmitVertex();

	EndPrimitive();
}