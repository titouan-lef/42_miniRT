/// @todo header

#include "minirt.h"

static void	inter_lateral_co(const t_cone *co, const t_math_co *mathco,
	const t_ray *ray, t_soluce *soluce)
{
	double	t;
	t_vec3	p;
	t_vec3	bp;
	double	m;
	t_vec3	m_odir;

	t = solve_eq_co(mathco, ray);
	if (t >= soluce->t)
		return ;
	p = ft_translation(&ray->s, &ray->dir, t);
	bp = ft_diff_vec3(&p, &mathco->b);
	m = ft_dot_vec3(&bp, &co->dir);
	if (m < 0 || m > co->h)
		return ;
	m_odir = ft_scalmult_vec3(&co->dir, m);
	soluce->t = t;
	soluce->p = p;
	soluce->n = ft_translation(&bp, &m_odir, -mathco->c_factor);
	soluce->n = ft_normalize_vec3(&soluce->n);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
static void	intersect_co(const t_cone *co, t_math_co *mathco,
	const t_ray *ray, t_soluce *soluce)
{
	double	t;
	t_vec3	p;
	t_vec3	n;

	mathco->raydir_dot_odir = ft_dot_vec3(&ray->dir, &co->dir);
	inter_lateral_co(co, mathco, ray, soluce);
	if (0 < mathco->raydir_dot_odir)
		n = ft_scalmult_vec3(&co->dir, -1);
	else
		n = co->dir;
	t = solve_eq_pl(mathco->ts_dot_odir, mathco->raydir_dot_odir);
	if (t < soluce->t)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathco->t) <= co->r)
			*soluce = create_soluce(t, &p, &n);
	}
}

void	intersect_ray_co(const t_obj *obj, t_intersec *inter)
{
	t_cone_obj	*co_obj;
	double	t;

	co_obj = (t_cone_obj *)obj->data;
	t = inter->soluce.t;
	intersect_co(&co_obj->co, &co_obj->mathco, &inter->ray, &inter->soluce);
	if (inter->soluce.t < t)
		inter->obj = obj;
}

double	intersect_light_co(const t_obj *obj, const t_ray *ray)
{
	t_soluce	soluce;
	t_cone_obj	*co_obj;
	t_math_co	mathco;

	co_obj = (t_cone_obj *)obj->data;
	soluce.t = INFINITY;
	init_math_co(&ray->s, &co_obj->co, &mathco);
	intersect_co(&co_obj->co, &mathco, ray, &soluce);
	return (soluce.t);
}
