/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:03:14 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:40:29 by tle-floc         ###   ########.fr       */
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
	proj = ft_translation(v, &pl->n, t);
	return (proj);
}
