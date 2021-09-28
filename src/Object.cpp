/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/09/28 16:43:04 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(void) { }
Object::Object(const Object &src) { *this = src; }
Object::~Object(void) { }

Object	&Object::operator=(const Object &rhs)
{
	this->position = rhs.position;
	this->velocity = rhs.velocity;
	this->mass = rhs.mass;
	this->angular_position = rhs.angular_position;
	this->angular_velocity = rhs.angular_velocity;
	this->dimension = rhs.dimension;
	this->diameter = rhs.diameter;
	return (*this);
}
