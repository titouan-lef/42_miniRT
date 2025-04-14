/// @todo header

#include "minirt.h"

void	intersect_ray_sp(const t_obj *obj, t_intersec *inter)
{
	t_sphere_obj	*sp_obj;
	double	t;

	sp_obj = (t_sphere_obj *)obj->data;
	t = solve_eq_sp(&sp_obj->mathsp, &inter->ray.dir);
	if (t >= inter->soluce.t)
		return ;
	inter->soluce.t = t;
	inter->soluce.p = ft_translation(&inter->ray.s, &inter->ray.dir, t);
	inter->soluce.n = ft_diff_vec3(&inter->soluce.p, &sp_obj->sp.pos);
	inter->soluce.n = ft_normalize_vec3(&inter->soluce.n);
	inter->obj = obj;
}

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
