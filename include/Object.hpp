/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/09/28 16:42:05 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "General.hpp"

class Object
{
	public :
		Object(void);
		Object(const Object &src);
		virtual ~Object(void);

		Object	&operator=(const Object &rhs);	/* REMEMBER TO UPDATE */

		vec3		position;
		vec3		velocity;
		float		mass;

		vec3		angular_position;	/* for cubes */
		vec3		angular_velocity;	/* for cubes */
		vec3		dimension;			/* for cubes */
		float		diameter;			/* for spheres */
};

#endif
