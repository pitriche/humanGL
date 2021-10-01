#version 410 core

in vec3		color_geometry;

out vec4	outColor;

void	main()
{
	outColor = vec4(color_geometry, 1.0);
}
