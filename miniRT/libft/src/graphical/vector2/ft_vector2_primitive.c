/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2_primitive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:09:54 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/06 13:46:39 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	ft_create_vec2(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

/**
 * @brief Create the normalized vector from 2 points.
 * @param p1 Start point of the vector.
 * @param p2 End point of the vector.
 * @return The vector p1p2 normalized.
 * @warning p1 must be different of p2.
 */
t_vec2	ft_create_normalized_vec2(const t_vec2 *p1, const t_vec2 *p2)
{
	t_vec2	v;

	v = ft_diff_vec2(p2, p1);
	v = ft_normalize_vec2(&v);
	return (v);
}

/**
 * @brief Normalize a vector, that is the same direction vector with a length
 * of 1.
 * @warning The vector must be a nonzero vector.
 */
t_vec2	ft_normalize_vec2(const t_vec2 *v)
{
	t_vec2	normalize;
	double	norm;

	norm = ft_norm_vec2(v);
	if (norm == 0)
	{
		ft_putendl_error("Error : try to normalize a zero vector2");
		return (*v);
	}
	normalize = ft_scalmult_vec2(v, 1.0 / norm);
	return (normalize);
}

/**
 * @brief Apply a translation on a point.
 * @param p Coordinates of the current point.
 * @param v Direction vector of the translation.
 * @param dist Distance of the translation.
 * @return Coordinates of the point after translation.
 * @warning v must be normalized if distance must be respected.
 */
t_vec2	ft_translation_vec2(const t_vec2 *p, const t_vec2 *v, double dist)
{
	t_vec2	new_p;

	new_p.x = p->x + v->x * dist;
	new_p.y = p->y + v->y * dist;
	return (new_p);
}
