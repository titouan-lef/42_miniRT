/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:03:14 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/21 16:38:33 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transformation.h"

t_vector3	ft_projection(t_vector3 v, t_plane p)
{
	double	numerator;
	double	denominator;
	double	t;

	numerator = p.a * v.x + p.b * v.y + p.c * v.z + p.d;
	denominator = p.a * p.a + p.b * p.b + p.c * p.c;
	t = -numerator / denominator;
	v = ft_create_vector3(p.a * t + v.x, p.b * t + v.y, p.c * t + v.z);
	return (v);
}
