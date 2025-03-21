/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_primitive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:29:42 by tle-floc          #+#    #+#             */
/*   Updated: 2024/12/11 16:18:43 by tle-floc         ###   ########.fr       */
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

double	ft_norm_vector3(t_vector3 v)
{
	double	dotproduct;
	double	norm;

	dotproduct = ft_dotproduct_vector3(v, v);
	norm = sqrt(dotproduct);
	return (norm);
}

double	ft_distance_vector3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	diff;
	double		norm;

	diff = ft_diff_vector3(v1, v2);
	norm = ft_norm_vector3(diff);
	return (norm);
}

t_vector3	ft_normalize_vector3(t_vector3 v)
{
	double	norm;

	norm = ft_norm_vector3(v);
	v = ft_scalarmult_vector3(v, 1.0 / norm);
	return (v);
}
