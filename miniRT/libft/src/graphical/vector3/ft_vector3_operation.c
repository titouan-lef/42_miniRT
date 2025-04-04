/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:09:41 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:23:45 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vec3	ft_sum_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	sum;

	sum.x = v1->x + v2->x;
	sum.y = v1->y + v2->y;
	sum.z = v1->z + v2->z;
	return (sum);
}

t_vec3	ft_diff_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	diff;

	diff.x = v1->x - v2->x;
	diff.y = v1->y - v2->y;
	diff.z = v1->z - v2->z;
	return (diff);
}

t_vec3	ft_scalmult_vec3(const t_vec3 *v, double k)
{
	t_vec3	scalarmult;

	scalarmult.x = v->x * k;
	scalarmult.y = v->y * k;
	scalarmult.z = v->z * k;
	return (scalarmult);
}

/**
 * @brief Get the dot product of 2 vectors v1 and v2, that is the result of
 * ||v1|| * ||v2|| * cos(v1, v2).
 */
double	ft_dot_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

/**
 * @brief Get the cross product of 2 vectors, that is the perpendicular vector
 * of this 2 vectors.
 * @return The perpendicular vector or a zero vector if the 2 vectors are
 * collinear.
 */
t_vec3	ft_cross_vec3(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	crossproduct;

	crossproduct.x = v1->y * v2->z - v1->z * v2->y;
	crossproduct.y = v1->z * v2->x - v1->x * v2->z;
	crossproduct.z = v1->x * v2->y - v1->y * v2->x;
	return (crossproduct);
}
