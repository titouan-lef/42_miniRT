/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_primitive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:09:54 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:23:45 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vec3	ft_create_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

/**
 * @brief Check if vector is a zero vector, that is a vector(0, 0, 0).
 */
int	ft_is_zero_vec3(const t_vec3 *v)
{
	return (v->x == 0 && v->y == 0 && v->z == 0);
}

/**
 * @brief Get the norm of a vector, that is its length.
 */
double	ft_norm_vec3(const t_vec3 *v)
{
	double	dotproduct;
	double	norm;

	dotproduct = ft_dot_vec3(v, v);
	norm = sqrt(dotproduct);
	return (norm);
}

/**
 * @brief Get the distance between 2 points.
 */
double	ft_distance_vec3(const t_vec3 *p1, const t_vec3 *p2)
{
	t_vec3	diff;
	double	norm;

	diff = ft_diff_vec3(p1, p2);
	norm = ft_norm_vec3(&diff);
	return (norm);
}

/**
 * @brief Normalize a vector, that is the same direction vector with a length
 * of 1.
 * @warning The vector must be a nonzero vector.
 */
t_vec3	ft_normalize_vec3(const t_vec3 *v)
{
	t_vec3	normalize;
	double	norm;

	norm = ft_norm_vec3(v);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero vector3");
		return (*v);
	}
	normalize = ft_scalmult_vec3(v, 1.0 / norm);
	return (normalize);
}
