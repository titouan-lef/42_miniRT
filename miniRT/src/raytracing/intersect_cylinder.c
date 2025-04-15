/// @todo header

#include "minirt.h"

static int	inter_lateral_cy(const t_cylinder *cy, double t, t_intersec *inter)
{
	t_vec3	p;
	t_vec3	op;
	double	m;
	t_vec3	m_odir;

	if (t >= inter->soluce.t)
		return (0);
	p = ft_translation(&inter->ray.s, &inter->ray.dir, t);
	op = ft_diff_vec3(&p, &cy->pos);
	m = ft_dot_vec3(&op, &cy->dir);
	if (fabs(m) > cy->hh)
		return (0);
	m_odir = ft_scalmult_vec3(&cy->dir, m);
	inter->soluce.t = t;
	inter->soluce.p = p;
	inter->soluce.n = ft_diff_vec3(&op, &m_odir);
	inter->soluce.n = ft_normalize_vec3(&inter->soluce.n);
	return (1);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
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
		update_n_soluce_pl(&cy->dir, mathcy->raydir_dot_odir, &inter->soluce);
	return (has_inter_base || has_inter_lateral);
}

void	intersect_ray_cy(const t_obj *obj, t_intersec *inter)
{
	t_cylinder_obj	*cy_obj;
	int				has_inter;

	cy_obj = (t_cylinder_obj *)obj->data;
	has_inter = intersect_cy(&cy_obj->cy, &cy_obj->mathcy, inter);
	if (has_inter)
		inter->obj = obj;
}

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
