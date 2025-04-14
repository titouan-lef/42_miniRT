/// @todo header

#include "minirt.h"

static void	inter_lateral_cy(const t_cylinder *cy, const t_math_cy *mathcy,
	const t_ray *ray, t_soluce *soluce)
{
	double	t;
	t_vec3	p;
	t_vec3	op;
	double	m;
	t_vec3	m_odir;

	t = solve_eq_cy(mathcy, ray);
	if (t >= soluce->t)
		return ;
	p = ft_translation(&ray->s, &ray->dir, t);
	op = ft_diff_vec3(&p, &cy->pos);
	m = ft_dot_vec3(&op, &cy->dir);
	if (fabs(m) > cy->hh)
		return ;
	m_odir = ft_scalmult_vec3(&cy->dir, m);
	soluce->t = t;
	soluce->p = p;
	soluce->n = ft_diff_vec3(&op, &m_odir);
	soluce->n = ft_normalize_vec3(&soluce->n);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
static void	intersect_cy(const t_cylinder *cy, t_math_cy *mathcy,
	const t_ray *ray, t_soluce *soluce)
{
	double	t;
	t_vec3	p;
	t_vec3	n;

	mathcy->raydir_dot_odir = ft_dot_vec3(&ray->dir, &cy->dir);
	inter_lateral_cy(cy, mathcy, ray, soluce);
	if (0 < mathcy->raydir_dot_odir)
		n = ft_scalmult_vec3(&cy->dir, -1);
	else
		n = cy->dir;
	t = solve_eq_pl(mathcy->bs_dot_odir, mathcy->raydir_dot_odir);
	if (t < soluce->t)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathcy->b) <= cy->r)
			*soluce = create_soluce(t, &p, &n);
	}
	t = solve_eq_pl(mathcy->ts_dot_odir, mathcy->raydir_dot_odir);
	if (t < soluce->t)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathcy->t) <= cy->r)
			*soluce = create_soluce(t, &p, &n);
	}
}

void	intersect_ray_cy(const t_obj *obj, t_intersec *inter)
{
	t_cylinder_obj	*cy_obj;
	double	t;

	cy_obj = (t_cylinder_obj *)obj->data;
	t = inter->soluce.t;
	intersect_cy(&cy_obj->cy, &cy_obj->mathcy, &inter->ray, &inter->soluce);
	if (inter->soluce.t < t)
		inter->obj = obj;
}

double	intersect_light_cy(const t_obj *obj, const t_ray *ray)
{
	t_soluce		soluce;
	t_cylinder_obj	*cy_obj;
	t_math_cy		mathcy;

	cy_obj = (t_cylinder_obj *)obj->data;
	soluce.t = INFINITY;
	init_math_cy(&ray->s, &cy_obj->cy, &mathcy);
	intersect_cy(&cy_obj->cy, &mathcy, ray, &soluce);
	return (soluce.t);
}
