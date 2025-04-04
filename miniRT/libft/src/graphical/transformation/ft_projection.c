/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:03:14 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:23:45 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_plane	ft_create_plane(const t_vec3 *n, const t_vec3 *p)
{
	t_plane	plane;

	plane.n = *n;
	plane.d = ft_dot_vec3(n, p);
	plane.d *= -1;
	return (plane);
}

t_vec3	ft_projection(const t_vec3 *v, const t_plane *pl)
{
	double	numerator;
	double	denominator;
	double	t;
	t_vec3	proj;

	numerator = pl->d;
	numerator += ft_dot_vec3(&pl->n, v);
	denominator = ft_dot_vec3(&pl->n, &pl->n);
	t = -numerator / denominator;
	proj = ft_scalmult_vec3(&pl->n, t);
	proj = ft_sum_vec3(&proj, v);
	return (proj);
}

/**
 * @brief Apply a translation on a point.
 * @param p Coordinates of the current point.
 * @param v Direction vector of the translation.
 * @param dist Distance of the translation.
 * @return Coordinates of the point after translation.
 * @warning v must be normalized if distance must be respected.
 */
t_vec3	ft_translation(const t_vec3 *p, const t_vec3 *v, double dist)
{
	t_vec3	new_p;

	new_p.x = p->x + v->x * dist;
	new_p.y = p->y + v->y * dist;
	new_p.z = p->z + v->z * dist;
	return (new_p);
}
