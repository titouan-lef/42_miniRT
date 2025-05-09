/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:48:28 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:48:30 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Update the soluce structure of inter if the point of intersection is
 * closer than the current one and on the latheral part of the cylinder.
 * If there is no intersection, nothing is updated.
 * @details EPSILON allows to avoid nose when same objects are in the same
 * place.
 * @param cy The cylinder.
 * @param t The closest potential factors t of the infinite cylinder.
 * @param inter The intersection structure.
 * @return 1 if the soluce structure is updated, 0 else.
 */
static int	inter_lateral_cy(const t_cylinder *cy, double t, t_intersec *inter)
{
	t_vec3	p;
	t_vec3	op;
	double	m;
	t_vec3	m_odir;
	t_vec3	n;

	if (t >= inter->soluce.t - EPSILON)
		return (0);
	p = ft_translation_vec3(&inter->ray.s, &inter->ray.dir, t);
	op = ft_diff_vec3(&p, &cy->pos);
	m = ft_dot_vec3(&op, &cy->dir);
	if (m < -cy->hh || m > cy->hh)
		return (0);
	m_odir = ft_scalmult_vec3(&cy->dir, m);
	inter->soluce.t = t;
	inter->soluce.p = p;
	n = ft_create_normalized_vec3(&m_odir, &op);
	update_n_soluce(&n, &inter->ray.dir, &inter->soluce);
	return (1);
}

/**
 * @brief Update the soluce structure of inter if the point of intersection is
 * closer than the current one. If there is no intersection, nothing is
 * updated.
 * @param cy The cylinder.
 * @param mathcy The pre-calculated mathematics.
 * @param inter The intersection structure.
 * @return An integer different of 0 if the soluce structure is updated.
 */
static int	intersect_cy(const t_cylinder *cy, t_math_cy *mathcy,
	t_intersec *inter)
{
	int		has_inter_lateral;
	int		has_inter_base;
	double	t;

	mathcy->raydir_dot_odir = ft_dot_vec3(&inter->ray.dir, &cy->dir);
	t = solve_eq_pl(mathcy->bs_dot_odir, mathcy->raydir_dot_odir);
	has_inter_base = intersect_base(&mathcy->b, cy->r, t, inter);
	t = solve_eq_pl(mathcy->ts_dot_odir, mathcy->raydir_dot_odir);
	has_inter_base += intersect_base(&mathcy->t, cy->r, t, inter);
	t = solve_eq_cy(mathcy, &inter->ray);
	has_inter_lateral = inter_lateral_cy(cy, t, inter);
	if (has_inter_base && !has_inter_lateral)
		update_n_soluce_lite(&cy->dir, mathcy->raydir_dot_odir, &inter->soluce);
	return (has_inter_base || has_inter_lateral);
}

/**
 * @brief Update the intersect structure if the point of intersection is closer
 * than the current one. If there is no intersection, nothing is updated.
 * @param obj The cylinder object.
 * @param inter The intersection structure.
 * @warning obj must be a cylinder object.
 */
void	intersect_ray_cy(const t_obj *obj, t_intersec *inter)
{
	t_cylinder_obj	*cy_obj;
	int				has_inter;

	cy_obj = (t_cylinder_obj *)obj->data;
	has_inter = intersect_cy(&cy_obj->cy, &cy_obj->mathcy, inter);
	if (has_inter)
		inter->obj = obj;
}

/**
 * @brief Get the factor t of the equation : p = s + t * dir.
 * p is the intersect point between the object and the ray.
 * s is the start of the ray.
 * dir is the direction of the ray.
 * t is a positive factor.
 * @param obj The cylinder object.
 * @param ray The ray.
 * @return A positive double or INFINITY if there is no solution.
 * @warning obj must be a cylinder object.
 */
double	intersect_light_cy(const t_obj *obj, const t_ray *ray)
{
	t_intersec		inter;
	t_cylinder_obj	*cy_obj;
	t_math_cy		mathcy;

	cy_obj = (t_cylinder_obj *)obj->data;
	inter.ray = *ray;
	inter.soluce.t = INFINITY;
	init_math_cy(&ray->s, &cy_obj->cy, &mathcy);
	intersect_cy(&cy_obj->cy, &mathcy, &inter);
	return (inter.soluce.t);
}
