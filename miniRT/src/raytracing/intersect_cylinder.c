/// @todo header

#include "minirt.h"

static int	is_in_height(const t_ray *ray, const t_cylinder *cy, double t)
{
	t_vec3	p;
	double	height;

	p = ft_translation(&ray->s, &ray->dir, t);
	p = ft_diff_vec3(&p, &cy->pos);
	height = ft_dot_vec3(&p, &cy->dir);
	if (height < 0)
		height = -height;
	return (height <= cy->hh);
}

static double	inter_infinite_cy(const t_cylinder *cy,
	const t_math_cy *mathcy, const t_ray *ray, double raydir_dot_odir)
{
	double	result;

	result = solve_eq_cy(mathcy, ray, raydir_dot_odir);
	if (result != INFINITY && !is_in_height(ray, cy, result))
		result = INFINITY;
	return (result);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
static double	intersect_cy(const t_cylinder *cy, const t_math_cy *mathcy,
	const t_ray *ray)
{
	double	result;
	double	raydir_dot_odir;
	double	t;
	t_vec3	p;

	raydir_dot_odir = ft_dot_vec3(&ray->dir, &cy->dir);
	result = inter_infinite_cy(cy, mathcy, ray, raydir_dot_odir);
	t = solve_eq_pl(mathcy->bs_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < result)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathcy->b) <= cy->r)
			result = t;
	}
	t = solve_eq_pl(mathcy->ts_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < result)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathcy->t) <= cy->r)
			result = t;
	}
	return (result);
}

double	intersect_ray_cy(const t_obj *obj, const t_ray *ray)
{
	double			result;
	t_cylinder_obj	*cy_obj;

	cy_obj = (t_cylinder_obj *)obj->data;
	result = intersect_cy(&cy_obj->cy, &cy_obj->mathcy, ray);
	return (result);
}

double	intersect_light_cy(const t_obj *obj, const t_ray *ray)
{
	double			result;
	t_cylinder_obj	*cy_obj;
	t_math_cy		mathcy;

	cy_obj = (t_cylinder_obj *)obj->data;
	init_math_cy(&ray->s, &cy_obj->cy, &mathcy);
	result = intersect_cy(&cy_obj->cy, &mathcy, ray);
	return (result);
}
