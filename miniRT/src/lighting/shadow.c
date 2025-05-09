/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:46:04 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:46:05 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Determine the smallest t factor of the intersection between an object
 * and the light ray (from light to intersection point).
 * @details Allow to know if light cross another object before reach the
 * current intersection point.
 * @return A positive double or INFINITY if there is no solution.
 */
static double	intersect_light(t_obj *obj, t_ray *ray)
{
	double	dist;

	if (obj->type == PLANE)
		dist = intersect_light_pl(obj, ray);
	else if (obj->type == SPHERE)
		dist = intersect_light_sp(obj, ray);
	else if (obj->type == CYLINDER)
		dist = intersect_light_cy(obj, ray);
	else if (obj->type == CONE)
		dist = intersect_light_co(obj, ray);
	else
		dist = INFINITY;
	return (dist);
}

/**
 * @brief Determine whether the object is in the shade or not
 * in order to know whether it's lighted or not.
 * @return 1 if the object is in the shadow, 0 else.
 */
int	shadow(t_obj **tab_obj, const t_light *light, const t_vec3 *p)
{
	t_ray	ray;
	double	dist;
	double	dist_min;

	ray.s = light->pos;
	if (ft_is_equal_vec3(p, &light->pos))
		return (1);
	ray.dir = ft_diff_vec3(p, &light->pos);
	dist_min = ft_norm_vec3(&ray.dir);
	ray.dir = ft_scalmult_vec3(&ray.dir, 1.0 / dist_min);
	while (*tab_obj != NULL)
	{
		dist = intersect_light(*tab_obj, &ray);
		if (dist < dist_min - EPSILON)
			return (1);
		++tab_obj;
	}
	return (0);
}
