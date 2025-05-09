/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:48:40 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:48:42 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Update the intersect structure if the point of intersection is closer
 * than the current one. If there is no intersection, nothing is updated.
 * @param obj The cylinder object.
 * @param inter The intersection structure.
 * @warning obj must be a cylinder object.
 */
void	intersect_ray_sp(const t_obj *obj, t_intersec *inter)
{
	t_sphere_obj	*sp_obj;
	double			t;

	sp_obj = (t_sphere_obj *)obj->data;
	t = solve_eq_sp(&sp_obj->mathsp, &inter->ray.dir);
	if (t >= inter->soluce.t - EPSILON)
		return ;
	inter->soluce.t = t;
	inter->obj = obj;
}

/**
 * @brief Get the factor t of the equation : p = s + t * dir.
 * p is the intersect point between the object and the ray.
 * s is the start of the ray.
 * dir is the direction of the ray.
 * t is a positive factor.
 * @param obj The sphere object.
 * @param ray The ray.
 * @return A positive double or INFINITY if there is no solution.
 * @warning obj must be a sphere object.
 */
double	intersect_light_sp(const t_obj *obj, const t_ray *ray)
{
	t_sphere_obj	*sp_obj;
	double			result;
	t_math_sp		mathsp;

	sp_obj = (t_sphere_obj *)obj->data;
	init_math_sp(&ray->s, &sp_obj->sp, &mathsp);
	result = solve_eq_sp(&mathsp, &ray->dir);
	return (result);
}
