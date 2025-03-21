/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:04 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/21 20:09:48 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_quaternion	ft_create_quaternion(double scalar, t_vector3 axis)
{
	t_quaternion	q;

	q.scalar = scalar;
	q.axis = axis;
	return (q);
}

t_quaternion	ft_sum_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;

	q.scalar = q1.scalar + q2.scalar;
	q.axis = ft_sum_vector3(q1.axis, q2.axis);
	return (q);
}

t_quaternion	ft_diff_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;

	q.scalar = q1.scalar - q2.scalar;
	q.axis = ft_diff_vector3(q1.axis, q2.axis);
	return (q);
}

t_quaternion	ft_scalarmult_quaternion(t_quaternion q, double k)
{
	q.scalar *= k;
	q.axis = ft_scalarmult_vector3(q.axis, k);
	return (q);
}

#include <stdio.h>
/**
 * @brief Get the product of 2 quaternions.
 * @warning The order of product is important.
 */
t_quaternion	ft_product_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;
	t_vector3		tmp;

	q.scalar = q1.scalar * q2.scalar - ft_dotproduct_vector3(q1.axis, q2.axis);
	q.axis = ft_scalarmult_vector3(q1.axis, q2.scalar);
	tmp = ft_scalarmult_vector3(q2.axis, q1.scalar);
	q.axis = ft_sum_vector3(q.axis, tmp);
	tmp = ft_crossproduct_vector3(q1.axis, q2.axis);
	q.axis = ft_sum_vector3(q.axis, tmp);
	return (q);
}

/**
 * @brief Get the norm of a quaternions.
 * @details The norm is also equal to the sqrt of the product of the quaternion
 * and its conjugation (here, the order of product isn't important).
 */
double	ft_norm_quaternion(t_quaternion q)
{
	double	norm;

	norm = q.scalar * q.scalar + ft_dotproduct_vector3(q.axis, q.axis);
	norm = sqrt(norm);
	return (norm);
}

t_quaternion	ft_unit_quaternion(t_quaternion q)
{
	double	norm;

	norm = ft_norm_quaternion(q);
	q = ft_scalarmult_quaternion(q, 1.0 / norm);
	return (q);
}

/**
 * @brief Get the conjugation of a quaternions.
 * @details The conjugation of a quaternion Q(real, imaginary) is
 * Q'(real, -imaginary). Real is the scalar part and imaginary the axis part.
 * @warning q value isn't modified.
 */
t_quaternion	ft_conjugation_quaternion(t_quaternion q)
{
	q.axis = ft_scalarmult_vector3(q.axis, -1);
	return (q);
}

/**
 * @warning Qaternion mustn't be null.
 */
t_quaternion	ft_inverse_quaternion(t_quaternion q)
{
	t_quaternion	inverse;
	double			norm;
	double			divisor;

	norm = ft_norm_quaternion(q);
	//if (norm == 0)
		//error
	divisor = 1.0 / (norm * norm);
	inverse = ft_conjugation_quaternion(q);
	inverse = ft_scalarmult_quaternion(inverse, divisor);
	return (inverse);
}
t_vector3	ft_rotation_quaternion(t_vector3 point, double angle, t_vector3 axis)
{
	t_quaternion	p;
	t_quaternion	q;
	t_quaternion	q_inverse;
	t_quaternion	result;
	double			tmp;

	q.scalar = cos(angle / 2.0);
	q.axis = ft_normalize_vector3(axis);
	tmp = sin(angle / 2.0);
	q.axis = ft_scalarmult_vector3(axis, tmp);

	q_inverse = ft_inverse_quaternion(q);

	p = ft_create_quaternion(0, point);
	result = ft_product_quaternion(q, p);

	result = ft_product_quaternion(result, q_inverse);
	return (result.axis);
}
