/// @todo header

#include "minirt.h"

double	intersect_ray_sphere(const t_obj *obj, const t_vec3 *ray_dir)
{
	double			result;
	t_sphere_obj	*sp_obj;

	sp_obj = (t_sphere_obj *)obj->data;
	result = solve_eq_sp(&sp_obj->mathsp, ray_dir);
	return (result);
}

double	intersect_light_sphere(const t_sphere *sp, const t_ray *ray)
{
	double		result;
	t_math_sp	mathsp;

	init_math_sp(&ray->s, sp, &mathsp);
	result = solve_eq_sp(&mathsp, &ray->dir);
	return (result);
}
