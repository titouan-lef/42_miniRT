/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:03:14 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/02 19:12:08 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_plane	ft_create_plane(t_vector3 n, t_vector3 p)
{
	t_plane	plane;

	plane.n = n;
	plane.d = -n.x * p.x - n.y * p.y - n.z * p.z;
	return (plane);
}

t_vector3	ft_projection(t_vector3 v, t_plane pl)
{
	double	numerator;
	double	denominator;
	double	t;

	numerator = pl.n.x * v.x + pl.n.y * v.y + pl.n.z * v.z + pl.d;
	denominator = pl.n.x * pl.n.x + pl.n.y * pl.n.y + pl.n.z * pl.n.z;
	t = -numerator / denominator;
	v = ft_create_vector3(pl.n.x * t + v.x, pl.n.y * t + v.y, pl.n.z * t + v.z);
	return (v);
}
