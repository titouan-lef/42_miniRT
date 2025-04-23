/// @todo header

#include "minirt.h"

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
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
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

void	intersect_ray_co(const t_obj *obj, t_intersec *inter)
{
	t_cone_obj	*co_obj;
	int			has_inter;

	co_obj = (t_cone_obj *)obj->data;
	has_inter = intersect_co(&co_obj->co, &co_obj->mathco, inter);
	if (has_inter)
		inter->obj = obj;
}

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
