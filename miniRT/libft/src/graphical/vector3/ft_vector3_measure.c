/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_measure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:51:50 by tle-floc          #+#    #+#             */
/*   Updated: 2025/04/04 11:52:31 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

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
