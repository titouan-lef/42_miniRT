/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quaternion_primitive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:04 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/03 13:55:40 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quaternion.h"

t_quat	ft_create_quat(double scalar, const t_vec3 *vec)
{
	t_quat	q;

	q.scalar = scalar;
	q.vec = *vec;
	return (q);
}

/**
 * @brief Get the norm of a quaternion.
 * @details The norm is also equal to the sqrt of the product of the quaternion
 * and its conjugation (here, the order of product isn't important).
 * A norm of size 0 occurs only with a quaterion(0, (0,0,0)).
 */
double	ft_norm_quat(const t_quat *q)
{
	double	norm;

	norm = q->scalar * q->scalar + ft_dotproduct_vec3(&q->vec, &q->vec);
	norm = sqrt(norm);
	return (norm);
}

/**
 * @brief Get the unit quaternion, that is a normalize quaternion.
 * @return A new quaternion.
 * @warning The quaternion must be a nonzero quaternion.
 */
t_quat	ft_unit_quat(const t_quat *q)
{
	t_quat	result;
	double	norm;

	norm = ft_norm_quat(q);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero quaternion");
		return (*q);
	}
	result = ft_scalarmult_quat(q, 1.0 / norm);
	return (result);
}

/**
 * @brief Get the conjugation of a quaternions.
 * @details The conjugation of a quaternion Q(real, imaginary) is
 * Q'(real, -imaginary). Real is the scalar part and imaginary the vector part.
 * @return A new quaternion.
 */
t_quat	ft_conjugate_quat(const t_quat *q)
{
	t_quat	result;

	result.scalar = q->scalar;
	result.vec = ft_scalarmult_vec3(&q->vec, -1);
	return (result);
}

/**
 * @brief Get the inverse quaternion.
 * @return A new quaternion.
 * @warning Quaternion must be a nonzero quaternion.
 */
t_quat	ft_inverse_quat(const t_quat *q)
{
	t_quat	inverse;
	double	norm;
	double	divisor;

	norm = ft_norm_quat(q);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero quaternion");
		return (*q);
	}
	divisor = 1.0 / (norm * norm);
	inverse = ft_conjugate_quat(q);
	inverse = ft_scalarmult_quat(&inverse, divisor);
	return (inverse);
}
