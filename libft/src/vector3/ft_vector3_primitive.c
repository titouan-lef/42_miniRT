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

double	ft_magnitude_vector3(t_vector3 v1)
{
	double	dotproduct;
	double	magnitude;

	dotproduct = ft_dotproduct_vector3(v1, v1);
	magnitude = sqrt(dotproduct);
	return (magnitude);
}

double	ft_distance_vector3(t_vector3 v1, t_vector3 v2)
{
	t_vector3	diff;
	double		magnitude;

	diff = ft_diff_vector3(v1, v2);
	magnitude = ft_magnitude_vector3(diff);
	return (magnitude);
}
