/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_primitive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:04 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/24 15:30:09 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quaternion	ft_create_quaternion(double scalar, t_vector3 axis)
{
	t_quaternion	q;

	q.scalar = scalar;
	q.axis = axis;
	return (q);
}

/**
 * @brief Get the norm of a quaternion.
 * @details The norm is also equal to the sqrt of the product of the quaternion
 * and its conjugation (here, the order of product isn't important).
 * A norm of size 0 occurs only with a quaterion(0, (0,0,0)).
 */
double	ft_norm_quaternion(t_quaternion q)
{
	double	norm;

	norm = q.scalar * q.scalar + ft_dotproduct_vector3(q.axis, q.axis);
	norm = sqrt(norm);
	return (norm);
}

/**
 * @brief Get the unit quaternion, that is a normalize quaternion.
 * @return A new quaternion.
 * @warning The quaternion must be a nonzero quaternion.
 */
t_quaternion	ft_unit_quaternion(t_quaternion q)
{
	double	norm;

	norm = ft_norm_quaternion(q);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero quaternion");
		return (q);
	}
	q = ft_scalarmult_quaternion(q, 1.0 / norm);
	return (q);
}

/**
 * @brief Get the conjugation of a quaternions.
 * @details The conjugation of a quaternion Q(real, imaginary) is
 * Q'(real, -imaginary). Real is the scalar part and imaginary the axis part.
 * @return A new quaternion.
 * @warning q value isn't modified.
 */
t_quaternion	ft_conjugate_quaternion(t_quaternion q)
{
	q.axis = ft_scalarmult_vector3(q.axis, -1);
	return (q);
}

/**
 * @brief Get the inverse quaternion.
 * @return A new quaternion.
 * @warning Quaternion must be a nonzero quaternion.
 */
t_quaternion	ft_inverse_quaternion(t_quaternion q)
{
	t_quaternion	inverse;
	double			norm;
	double			divisor;

	norm = ft_norm_quaternion(q);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero quaternion");
		return (q);
	}
	divisor = 1.0 / (norm * norm);
	inverse = ft_conjugate_quaternion(q);
	inverse = ft_scalarmult_quaternion(inverse, divisor);
	return (inverse);
}
