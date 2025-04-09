/// @todo header

#include "minirt.h"

double	intersect_ray_sp(const t_obj *obj, const t_vec3 *ray_dir)
{
	double			result;
	t_sphere_obj	*sp_obj;

	sp_obj = (t_sphere_obj *)obj->data;
	result = solve_eq_sp(&sp_obj->mathsp, ray_dir);
	return (result);
}

double	intersect_light_sp(const t_obj *obj, const t_ray *ray)
{
	double			result;
	t_sphere_obj	*sp_obj;
	t_math_sp		mathsp;

	sp_obj = (t_sphere_obj *)obj->data;
	init_math_sp(&ray->s, &sp_obj->sp, &mathsp);
	result = solve_eq_sp(&mathsp, &ray->dir);
	return (result);
}
