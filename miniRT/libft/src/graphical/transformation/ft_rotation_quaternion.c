/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_quaternion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:41:26 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/24 15:29:06 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

/**
 * @brief Create a unit quaternion.
 * @details Normalize axis vector allows to get directly a unit quaternion.
 * It's more optimize that create a quaternion and normalize its after.
 * @warning Axis must be a nonzero vector3.
 */
static t_quaternion	ft_create_unit_quaternion(double angle, t_vector3 axis)
{
	t_quaternion	q;
	double			sinus;
	t_vector3		normalize_axis;

	q.scalar = cos(angle / 2.0);
	sinus = sin(angle / 2.0);
	normalize_axis = ft_normalize_vector3(axis);
	q.axis = ft_scalarmult_vector3(normalize_axis, sinus);
	return (q);
}

/**
 * @brief Apply a rotation on the point/vector define by a angle rotation
 * around an axis.
 * @details q is an unit quaternion, so its inverse is its conjugate.
 * @param v Point or vector to rotate.
 * @param angle Rotation angle (in radian).
 * @param axis Rotation axis (it can be not normalized).
 * @return The position of the point after the rotation.
 * @warning Axis must be a nonzero vector3.
 */
t_vector3	ft_rotation_quaternion(t_vector3 v, double angle, t_vector3 axis)
{
	t_quaternion	p;
	t_quaternion	q;
	t_quaternion	q_inverse;
	t_quaternion	result;

	q = ft_create_unit_quaternion(angle, axis);
	q_inverse = ft_conjugate_quaternion(q);
	p = ft_create_quaternion(0, v);
	result = ft_product_quaternion(q, p);
	result = ft_product_quaternion(result, q_inverse);
	return (result.axis);
}
