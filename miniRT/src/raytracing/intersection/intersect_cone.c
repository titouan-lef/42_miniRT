/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:48:22 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:48:24 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Update the soluce structure of inter if the point of intersection is
 * closer than the current one and on the latheral part of the cone.
 * If there is no intersection, nothing is updated.
 * @details EPSILON allows to avoid nose when same objects are in the same
 * place. It's in this function that is defined if the intersection is on the
 * visible part of the infinite cone.
 * @param co The cone.
 * @param mathco The pre-calculated mathematics.
 * @param t One of the two potential factors t of the infinite cone.
 * @param inter The intersection structure.
 * @return 1 if the soluce structure is updated, 0 else.
 */
static int	inter_lateral_co(const t_cone *co, const t_math_co *mathco,
	double t, t_intersec *inter)
{
	t_vec3	p;
	t_vec3	bp;
	double	m;
	t_vec3	m_odir;
	t_vec3	n;

	if (t >= inter->soluce.t - EPSILON)
		return (0);
	p = ft_translation_vec3(&inter->ray.s, &inter->ray.dir, t);
	bp = ft_diff_vec3(&p, &mathco->b);
	m = ft_dot_vec3(&bp, &co->dir);
	if (m <= 0 || m > co->h)
		return (0);
	m_odir = ft_scalmult_vec3(&co->dir, m);
	inter->soluce.t = t;
	inter->soluce.p = p;
	n = ft_translation_vec3(&bp, &m_odir, -mathco->angle_factor);
	n = ft_normalize_vec3(&n);
	update_n_soluce(&n, &inter->ray.dir, &inter->soluce);
	return (1);
}

/**
 * @brief Update the soluce structure of inter if the point of intersection is
 * closer than the current one. If there is no intersection, nothing is
 * updated.
 * @details The two potential factors are calculated and not the closest
 * because quadratic equation don't allow to know if the intersection is on the
 * visible part of the infinite cone.
 * @param co The cone.
 * @param mathco The pre-calculated mathematics.
 * @param inter The intersection structure.
 * @return An integer different of 0 if the soluce structure is updated.
 */
static int	intersect_co(const t_cone *co, t_math_co *mathco, t_intersec *inter)
{
	int		has_inter_lateral;
	int		has_inter_base;
	double	t[2];

	mathco->raydir_dot_odir = ft_dot_vec3(&inter->ray.dir, &co->dir);
	t[0] = solve_eq_pl(mathco->ts_dot_odir, mathco->raydir_dot_odir);
	has_inter_base = intersect_base(&mathco->t, co->r, t[0], inter);
	solve_eq_co(mathco, &inter->ray, t);
	has_inter_lateral = inter_lateral_co(co, mathco, t[0], inter);
	has_inter_lateral += inter_lateral_co(co, mathco, t[1], inter);
	if (has_inter_base && !has_inter_lateral)
		update_n_soluce_lite(&co->dir, mathco->raydir_dot_odir, &inter->soluce);
	return (has_inter_base || has_inter_lateral);
}

/**
 * @brief Update the intersect structure if the point of intersection is closer
 * than the current one. If there is no intersection, nothing is updated.
 * @param obj The cone object.
 * @param inter The intersection structure.
 * @warning obj must be a cone object.
 */
void	intersect_ray_co(const t_obj *obj, t_intersec *inter)
{
	t_cone_obj	*co_obj;
	int			has_inter;

	co_obj = (t_cone_obj *)obj->data;
	has_inter = intersect_co(&co_obj->co, &co_obj->mathco, inter);
	if (has_inter)
		inter->obj = obj;
}

/**
 * @brief Get the factor t of the equation : p = s + t * dir.
 * p is the intersect point between the object and the ray.
 * s is the start of the ray.
 * dir is the direction of the ray.
 * t is a positive factor.
 * @param obj The cone object.
 * @param ray The ray.
 * @return A positive double or INFINITY if there is no solution.
 * @warning obj must be a cone object.
 */
double	intersect_light_co(const t_obj *obj, const t_ray *ray)
{
	t_intersec	inter;
	t_cone_obj	*co_obj;
	t_math_co	mathco;

	co_obj = (t_cone_obj *)obj->data;
	inter.ray = *ray;
	inter.soluce.t = INFINITY;
	init_math_co(&ray->s, &co_obj->co, &mathco);
	intersect_co(&co_obj->co, &mathco, &inter);
	return (inter.soluce.t);
}
