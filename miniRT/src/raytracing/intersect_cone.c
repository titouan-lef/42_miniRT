/// @todo header

#include "minirt.h"

static int	is_in_height(const t_ray *ray, const t_cone *co, const t_math_co *mathco, double t)
{
	t_vec3	p;
	t_vec3	bp;
	double	height;

	p = ft_translation(&ray->s, &ray->dir, t);
	bp = ft_diff_vec3(&p, &mathco->b);
	height = ft_dot_vec3(&bp, &co->dir);
	return (height <= co->h && height > 0);
}

static double	inter_infinite_co(const t_cone *co,
	const t_math_co *mathco, const t_ray *ray, double raydir_dot_odir)
{
	double	result;

	result = solve_eq_co(mathco, ray, raydir_dot_odir);
	if (result != INFINITY && !is_in_height(ray, co, mathco, result))
		result = INFINITY;
	return (result);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
static double	intersect_co(const t_cone *co, const t_math_co *mathco,
	const t_ray *ray)
{
	double	result;
	double	raydir_dot_odir;
	double	t;
	t_vec3	p;

	raydir_dot_odir = ft_dot_vec3(&ray->dir, &co->dir);
	result = inter_infinite_co(co, mathco, ray, raydir_dot_odir);
	t = solve_eq_pl(mathco->ts_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < result)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathco->t) <= co->r)
			result = t;
	}
	return (result);
}

double	intersect_ray_co(const t_obj *obj, const t_ray *ray)
{
	double			result;
	t_cone_obj	*co_obj;

	co_obj = (t_cone_obj *)obj->data;
	result = intersect_co(&co_obj->co, &co_obj->mathco, ray);
	return (result);
}

double	intersect_light_co(const t_obj *obj, const t_ray *ray)
{
	double			result;
	t_cone_obj	*co_obj;
	t_math_co		mathco;

	co_obj = (t_cone_obj *)obj->data;
	init_math_co(&ray->s, &co_obj->co, &mathco);
	result = intersect_co(&co_obj->co, &mathco, ray);
	return (result);
}
