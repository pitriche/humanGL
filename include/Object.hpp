/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/10/01 13:04:58 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "General.hpp"
# include "Matrix.hpp"

class Object
{
	public :
		Object(void);
		Object(const Object &src);
		virtual ~Object(void);

		Object	&operator=(const Object &rhs);	/* REMEMBER TO UPDATE */


		Matrix 		GetModel() const;
		Matrix 		model; /* translation et rotation */

		Matrix		rotate;
		Matrix		translate;


		vec3		dimensions;
		Object		*root_part;
		

};

#endif
