/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_operation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:39:02 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:38:26 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

/**
 * @brief Get the sum of 2 quaternions.
 * @return A new quaternion.
 */
t_quat	ft_sum_quat(const t_quat *q1, const t_quat *q2)
{
	t_quat	q;

	q.scalar = q1->scalar + q2->scalar;
	q.vec = ft_sum_vec3(&q1->vec, &q2->vec);
	return (q);
}

/**
 * @brief Get the difference of 2 quaternions.
 * @return A new quaternion.
 */
t_quat	ft_diff_quat(const t_quat *q1, const t_quat *q2)
{
	t_quat	q;

	q.scalar = q1->scalar - q2->scalar;
	q.vec = ft_diff_vec3(&q1->vec, &q2->vec);
	return (q);
}

/**
 * @brief Get the product of a quaternion and a scalar.
 * @return A new quaternion.
 */
t_quat	ft_scalarmult_quat(const t_quat *q, double k)
{
	t_quat	result;

	result.scalar = q->scalar * k;
	result.vec = ft_scalmult_vec3(&q->vec, k);
	return (result);
}

/**
 * @brief Get the product of 2 quaternions.
 * @details scalar result = q1.s * q2.s - q1->v . q2.v and
 * vector result = q1.v ^ q2.v + q1.v * q2.s + q2.v * q1.s
 * @return A new quaternion.
 * @warning The order of product is important.
 */
t_quat	ft_product_quat(const t_quat *q1, const t_quat *q2)
{
	t_quat	q;

	q.scalar = q1->scalar * q2->scalar - ft_dot_vec3(&q1->vec, &q2->vec);
	q.vec = ft_cross_vec3(&q1->vec, &q2->vec);
	q.vec = ft_translation(&q.vec, &q1->vec, q2->scalar);
	q.vec = ft_translation(&q.vec, &q2->vec, q1->scalar);
	return (q);
}
