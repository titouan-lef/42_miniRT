/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:39:02 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/24 15:19:35 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

/**
 * @brief Get the sum of 2 quaternions.
 * @return A new quaternion.
 */
t_quaternion	ft_sum_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;

	q.scalar = q1.scalar + q2.scalar;
	q.axis = ft_sum_vector3(q1.axis, q2.axis);
	return (q);
}

/**
 * @brief Get the difference of 2 quaternions.
 * @return A new quaternion.
 */
t_quaternion	ft_diff_quaternion(t_quaternion q1, t_quaternion q2)
{
	t_quaternion	q;

	q.scalar = q1.scalar - q2.scalar;
	q.axis = ft_diff_vector3(q1.axis, q2.axis);
	return (q);
}

/**
 * @brief Get the product of a quaternion and a scalar.
 * @return A new quaternion.
 */
t_quaternion	ft_scalarmult_quaternion(t_quaternion q, double k)
{
	q.scalar *= k;
	q.axis = ft_scalarmult_vector3(q.axis, k);
	return (q);
}

/**
 * @brief Get the product of 2 quaternions.
 * @return A new quaternion.
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
