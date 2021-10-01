/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/01 14:10:10 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "All.hpp"

Game::Game(void) : game_speed(1.0f), gravity(9.80665f) { }
Game::~Game(void) { }

void	Game::init(void)
{
	Object	tmp;
	Object	tmp2;

	/* initial camera position, unlocked */
	SDL_SetRelativeMouseMode(SDL_TRUE);
	this->pos[2] = -4.0f;
	this->pos[1] = 1.0f;
	this->pos_locked = 8.0f;
	this->obj.reserve(1000);


	/* obj[0] Tronc*/
	tmp.model = Matrix();
	tmp.rotate = Matrix().rotate(0,0,0);
	tmp.translate = Matrix().translate(0,0,0);
	tmp.root_part = 0;
	tmp.dimensions = {1.5,5,1.5};
	this->obj.push_back(tmp);

	/* obj[1] tete*/
	tmp.model = Matrix();
	tmp.rotate = Matrix().rotate(0,0,0);
	tmp.translate = Matrix().translate(0,3,0);
	tmp.root_part = &this->obj[0];
	tmp.dimensions = {2,2,2};
	this->obj.push_back(tmp);

	/* obj[2] articulation bras droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(1.2,1.5,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);

	/* obj[3] bras droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[2];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);

	/* obj[4] articulation bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(1,0,0);
	tmp2.translate = Matrix().translate(-1.2,1.5,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);


	/* obj[5] bras gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[4];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);


/* obj[6] articulation jambe droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(-1,0,0);
	tmp2.translate = Matrix().translate(0.3,-2,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);

	/* obj[7] articulation jambe gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(1,0,0);
	tmp2.translate = Matrix().translate(-0.3,-2,0);
	tmp2.root_part = &this->obj[0];
	tmp2.dimensions = {1,1,1};
	this->obj.push_back(tmp2);


	/* obj[8] jambe droit*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[6];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);


	/* obj[9] jambe gauche*/
	tmp2.model = Matrix();
	tmp2.rotate = Matrix().rotate(0,0,0);
	tmp2.translate = Matrix().translate(0,-1,0);
	tmp2.root_part = &this->obj[7];
	tmp2.dimensions = {1,2.5,1};
	this->obj.push_back(tmp2);



	// tmp.model = Matrix().translate(-1.8, -2, -2).rotate(2, 0, 0);
	// tmp.root_part = &this->obj[0];
	// tmp.dimensions = {1,1,5};
	// this->obj.push_back(tmp);


	// tmp.model = Matrix().translate(10,10,10);//.rotate(1, 0, 0);;
	// tmp.root_part = &this->obj[1];
	// tmp.dimensions = {5,10,4};

	// this->obj.push_back(tmp);
	
	
	std::cout << "obj[0]:"<< &this->obj[0] << std::endl;
	std::cout << "obj[1]:"<< &this->obj[1] << std::endl;
	std::cout << "obj[2]:"<< &this->obj[2] << std::endl;


	// std::cout << "obj[0].root_part:"<< this->obj[0].root_part << std::endl; 
	// std::cout << "obj[1].root_part:"<< this->obj[1].root_part << std::endl;
	// std::cout << "obj[2].root_part:"<< this->obj[2].root_part << std::endl;


	std::cout << "obj[0].root_part:"<< this->obj[0].root_part << "-->" << "0"<<std::endl; 
	std::cout << "obj[1].root_part:"<< this->obj[1].root_part << "-->" << &this->obj[0]<<std::endl; 
	std::cout << "obj[2].root_part:"<< this->obj[2].root_part << "-->" << &this->obj[1] <<std::endl; 
	/* objects */




	// this->obj.push_back(tmp);

	// tmp.position = {1, 1, 0};
	// tmp.angular_velocity = {0, 0, 0};
	// tmp.diameter = 1;
	// this->obj.push_back(tmp);

	// tmp.position = {0, 0.5, 0};
	// tmp.angular_velocity = {0.3f, 0.5f, 0.8f};
	// tmp.diameter = 1;
	// this->obj.push_back(tmp);

	// /* cardinal boxes */
	// tmp.position = {3, 0, 0};
	// tmp.angular_velocity = {0, 0, 0};
	// tmp.dimension = {2, 0.5f, 0.5f};
	// this->obj.push_back(tmp);

	// tmp.position = {0, 0, 3};
	// tmp.dimension = {0.2f, 0.2f, 4};
	// this->obj.push_back(tmp);


	// tmp.position = {0, 3, 0};
	// tmp.dimension = {0.6f, 3, 0.6f};
	// this->obj.push_back(tmp);

	// tmp.position = {1, 3, 4};
	// tmp.velocity = {0, 0, 0};
	// tmp.diameter = 1;
	// this->obj.push_back(tmp);
}

/* ########################################################################## */

void		Game::_update_camera(float delta, const Keys &key)
{
	float	delta_x;
	float	delta_z;

	/* lock - unlock camera and cursor */
	if (this->camera_lock != (enum e_camera)key.mouse_middle)
	{
		this->camera_lock = key.mouse_middle ? Locked : Unlocked;
		if (this->camera_lock == Unlocked)
			SDL_SetRelativeMouseMode(SDL_TRUE);
		else if (this->camera_lock == Locked)
			SDL_SetRelativeMouseMode(SDL_FALSE);
	}

	/* set then cap look angles */
	this->look_yaw += (key.mouse_x * MOUSE_SENSITIVITY_X) / 100000.0f;
	this->look_pitch += (key.mouse_y * MOUSE_SENSITIVITY_Y) / 100000.0f;
	if (this->look_pitch < -LOOK_CAP_PITCH)
		this->look_pitch = -LOOK_CAP_PITCH;
	if (this->look_pitch > LOOK_CAP_PITCH)
		this->look_pitch = LOOK_CAP_PITCH;
	if (this->camera_lock == Locked && this->look_pitch < LOOK_CAP_PITCH_LOCK)
		this->look_pitch = LOOK_CAP_PITCH_LOCK;

	/* set and cap positions */
	this->pos[1] += (unsigned)key.space * delta * CAMERA_SPEED -
	(unsigned)key.lshift * delta * CAMERA_SPEED;
	if (this->pos[1] < POS_CAP_Y)
		this->pos[1] = POS_CAP_Y;
	
	delta_x = (unsigned)key.d * delta * CAMERA_SPEED -
	(unsigned)key.a * delta * CAMERA_SPEED;
	delta_z = (unsigned)key.w * delta * CAMERA_SPEED -
	(unsigned)key.s * delta * CAMERA_SPEED;
	this->pos[0] += delta_z * sinf(this->look_yaw) +
	delta_x * sinf(this->look_yaw + (float)M_PI_2);
	this->pos[2] += delta_z * cosf(this->look_yaw) +
	delta_x * cosf(this->look_yaw + (float)M_PI_2);

	this->pos_locked += key.mouse_scroll / 1000.0f * SCROLL_SENSITIVITY;
	if (this->pos_locked < 0)
		this->pos_locked = 0;

	glUniform3fv(all.gl.uniform.camera_pos, 1, this->pos.data());
}

void		Game::_update_objects(float delta, const Keys &key)
{
	(void)key;
	static unsigned anim = 0;
	delta *= this->game_speed;

	// for (Object &obj : this->obj)
	// {
	// 	obj.position[0] += obj.velocity[0] * delta;
	// 	obj.position[1] += obj.velocity[1] * delta;
	// 	obj.position[2] += obj.velocity[2] * delta;
	// 	obj.angular_position[0] += obj.angular_velocity[0] * delta;
	// 	obj.angular_position[1] += obj.angular_velocity[1] * delta;
	// 	obj.angular_position[2] += obj.angular_velocity[2] * delta;
	// }
	
	
	
	
	 static Matrix mat;

	 mat.rotate(delta , 0, 0);
		obj[2].rotate = mat * obj[3].rotate;// =obj[1].model.rotate(delta, 0, 0);

 	
	 
	 
	 
	 
	 
	 
	 
	 // 		//  std::cout << anim << std::endl;

 	// 	// std::cout << delta << std::endl;
	
 		// if (anim == 0)
		// {
 		// 	// std::cout << obj[1].angular_position[0] << std::endl;
			
		// 	obj[1].model.translate(0, 0, 0).rotate(delta, 0, 0);
		// 	 if (obj[1].angular_position[0] >= 0.5){
		// 		 anim = 1;

				
		// 	}
		// }

		// if (anim == 1)
		// {
		
		// }
	

	



// 	for (Object &obj : this->obj)
// 	{
// 		if (delta < 0.1)
// 		{

// 		}
// 		else{

// //			obj.position[4] -=  delta ;
// 		}

		
	// }
	/* wiggle all */
	// this->obj[2].position[0] = sinf(all.time.elapsed_frame() / 20.0f) * 4.8f;
	// this->obj[2].position[2] = cosf(all.time.elapsed_frame() / 20.0f) * 4.8f;
	// this->obj[1].position[0] = 1 + cosf(all.time.elapsed_frame() / 60.0f) * 1.8f;
	// this->obj[1].position[1] = sinf(all.time.elapsed_frame() / 60.0f) * 1.8f;
	// this->obj[2].dimension[0] = sinf(all.time.elapsed_frame() / 10.0f) * 1.8f;
	// this->obj[2].dimension[1] = cosf(all.time.elapsed_frame() / 8.0f) * 2.3f;
	// this->obj[2].dimension[2] = -cosf(all.time.elapsed_frame() / 3.0f) * 5.0f;
}

void		Game::update(float delta, const Keys &key)
{
	this->_update_camera(delta, key);
	this->_update_objects(delta, key);
}
