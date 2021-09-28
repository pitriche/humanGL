/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/-/27 12:54:54 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenGL.hpp"
#include "General.hpp"
#include "Utils.hpp"

OpenGL::OpenGL(void) { }

/* ########################################################################## */
/* #####################			Buffers				##################### */
/* ########################################################################## */

void	OpenGL::_init_vao(void)
{
	/* looking towards positive Z, triangle fans, side length 2 */
	float	obj_data[] =
	{
		/* cube */
		-1,	1,	-1,		1,	1,	-1,		1,	-1,	-1,		-1,	-1,	-1,	/* front */
		-1,	1,	1,		1,	1,	1,		1,	-1,	1,		-1,	-1,	1,	/* back */
		-1,	1,	1,		-1,	1,	-1,		-1,	-1,	-1,		-1,	-1,	1,	/* left */
		1,	1,	1,		1,	1,	-1,		1,	-1,	-1,		1,	-1,	1,	/* right */
		-1,	-1,	-1,		1,	-1,	-1,		1,	-1,	1,		-1,	-1,	1,	/* bottom */
		-1,	1,	-1,		1,	1,	-1,		1,	1,	1,		-1,	1,	1,	/* top */
	};

	/* bring radius and side length to 1 */
	for (unsigned i = 0; i < (sizeof(obj_data) / 4); ++i)
		obj_data[i] *= 0.5f;

	/* init and select vao */
	glGenVertexArrays(1, &this->terrain.vao);
	glBindVertexArray(this->terrain.vao);
	std::cout << "VAO:[" << this->terrain.vao << "/1]\t";

	/* init and fill vbo with cube data */
	glGenBuffers(1, &this->terrain.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, this->terrain.vbo);
	std::cout << "VBO:[" << this->terrain.vbo << "/1]" << std::endl;
	glBufferData(GL_ARRAY_BUFFER, sizeof(obj_data), obj_data, GL_STATIC_DRAW);

	/* init attributes */
	this->terrain.att.position_vertex =
	(GLuint)glGetAttribLocation(this->shader.program, "position_vertex");
	glVertexAttribPointer(this->terrain.att.position_vertex, 3, GL_FLOAT,
		GL_FALSE, sizeof(float) * 3, (void *)(0));
	glEnableVertexAttribArray(this->terrain.att.position_vertex);
}

/* ########################################################################## */
/* #####################			Shaders				##################### */
/* ########################################################################## */

static GLuint compile_shader(const char *filename, GLenum type)
{
	GLuint		shader;
	std::string	scode;
	const char	*code;
	GLint		status;

	/* fetch code in stack */
	scode = Utils::read_file(filename);
	code = scode.c_str();
	shader = glCreateShader(type);
	glShaderSource(shader, 1, &code, 0);

	/* compile and check for errors */
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
		Utils::openGL_error_log(shader, status, filename);
	return (shader);
}

void	OpenGL::_init_shader(void)
{
	this->shader.vertex = compile_shader("shader/vertex.glsl",
		GL_VERTEX_SHADER);
	// this->shader.geometry = compile_shader("shader/geometry.glsl",
	// 	GL_GEOMETRY_SHADER);
	this->shader.fragment = compile_shader("shader/fragment.glsl",
		GL_FRAGMENT_SHADER);

	/* create shader program and attach shaders */
	this->shader.program = glCreateProgram();
	std::cout << "Program: [" << this->shader.program << "/3]" << std::endl;
	glAttachShader(this->shader.program, this->shader.vertex);
	// glAttachShader(this->shader.program, this->shader.geometry); // geometry
	glAttachShader(this->shader.program, this->shader.fragment);
	glBindFragDataLocation(this->shader.program, 0, "outColor");

	/* link and use shader program */
	glLinkProgram(this->shader.program);
	glUseProgram(this->shader.program);
}

/* ########################################################################## */
/* #####################		Uniforms & Data			##################### */
/* ########################################################################## */

void	OpenGL::_init_uniform(void)
{
	this->uniform.matrix_proj = glGetUniformLocation(this->shader.program,
		"matrix_proj");
	this->uniform.matrix_view = glGetUniformLocation(this->shader.program,
		"matrix_view");
	this->uniform.matrix_model = glGetUniformLocation(this->shader.program,
		"matrix_model");

	this->uniform.color = glGetUniformLocation(this->shader.program,
		"color");
	this->uniform.camera_pos = glGetUniformLocation(this->shader.program,
		"camera_pos");
}

void	OpenGL::_init_matrix(void)
{
	this->matrix_model = Matrix();
	this->matrix_view = Matrix();
	this->matrix_proj.set_projection((float)M_PI * CAMERA_FOV / 360.0f,
		CAMERA_NEAR, CAMERA_FAR, (float)WIN_SIZEX / WIN_SIZEY);

	glUniformMatrix4fv(this->uniform.matrix_model, 1, true,
		this->matrix_model.data());
	glUniformMatrix4fv(this->uniform.matrix_view, 1, true,
		this->matrix_view.data());
	glUniformMatrix4fv(this->uniform.matrix_proj, 1, true,
		this->matrix_proj.data());
}

/* ########################################################################## */
/* #####################			Main init			##################### */
/* ########################################################################## */

void	OpenGL::init(SDL_Window *window)
{
	/* create OpenGL context */
	this->glcontext = SDL_GL_CreateContext(window);
	std::cout << "Supported OpenGL version: " << glGetString(GL_VERSION) <<
		std::endl << "Using OpenGL " << OPENGL_VERSION_MAJOR << '.' <<
		OPENGL_VERSION_MINOR << std::endl << std::endl;

	this->_init_shader();
	this->_init_uniform();
	this->_init_vao();
	this->_init_matrix();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.243f, 0.243f, 0.241f, 1.0f);
}
