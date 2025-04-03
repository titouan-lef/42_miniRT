/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_quaternion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:41:26 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/03 13:52:39 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

/**
 * @brief Create a unit quaternion.
 * @details Normalize vector part allows to get directly a unit quaternion.
 * It's more optimize that create a quaternion and normalize its after.
 * @warning Vec must be a nonzero vector3.
 */
static t_quat	ft_create_unit_quat(double angle, const t_vec3 *vec)
{
	t_quat	q;
	double	sinus;
	t_vec3	normalize_vec;

	q.scalar = cos(angle / 2.0);
	sinus = sin(angle / 2.0);
	normalize_vec = ft_normalize_vec3(vec);
	q.vec = ft_scalarmult_vec3(&normalize_vec, sinus);
	return (q);
}

/**
 * @brief Apply a rotation on the point/vector define by a angle rotation
 * around an axis.
 * @details q is an unit quaternion, so its inverse is its conjugate.
 * @param v Point or vector to rotate.
 * @param angle Rotation angle (in radian).
 * @param vec Rotation axis (it can be not normalized).
 * @return The position of the point after the rotation.
 * @warning Axis must be a nonzero vector3.
 */
t_vec3	ft_rotation_quat(const t_vec3 *v, double angle, const t_vec3 *vec)
{
	t_quat	p;
	t_quat	q;
	t_quat	q_inverse;
	t_quat	result;

	q = ft_create_unit_quat(angle, vec);
	q_inverse = ft_conjugate_quat(&q);
	p = ft_create_quat(0, v);
	result = ft_product_quat(&q, &p);
	result = ft_product_quat(&result, &q_inverse);
	return (result.vec);
}
