/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_primitive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:09:54 by tle-floc          #+#    #+#             */
/*   Updated: 2025/03/26 14:49:27 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3	ft_create_vector3(double x, double y, double z)
{
	t_vector3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

/**
 * @brief Get the norm of a vector, that is its length.
 */
double	ft_norm_vector3(t_vector3 v)
{
	double	dotproduct;
	double	norm;

	dotproduct = ft_dotproduct_vector3(v, v);
	norm = sqrt(dotproduct);
	return (norm);
}

/**
 * @brief Get the distance between 2 points.
 */
double	ft_distance_vector3(t_vector3 p1, t_vector3 p2)
{
	t_vector3	diff;
	double		norm;

	diff = ft_diff_vector3(p1, p2);
	norm = ft_norm_vector3(diff);
	return (norm);
}

/**
 * @brief Normalize a vector, that is the same direction vector with a length of 1.
 * @warning The vector must be a nonzero vector.
 */
t_vector3	ft_normalize_vector3(t_vector3 v)
{
	double	norm;

	norm = ft_norm_vector3(v);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero vector3");
		return (v);
	}
	v = ft_scalarmult_vector3(v, 1.0 / norm);
	return (v);
}
