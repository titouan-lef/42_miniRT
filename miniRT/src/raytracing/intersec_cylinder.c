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

static double	a_calculation(double raydir_dot_odir)
{
	return (1 - raydir_dot_odir * raydir_dot_odir);
}

static double	b_calculation(const t_vec3 *os, const t_vec3 *raydir,
	double os_dot_odir, double raydir_dot_odir)
{
	double	dot;

	dot = ft_dot_vec3(os, raydir);
	return (2.0 * (dot - os_dot_odir * raydir_dot_odir));
}

static double	inter_infinite_cy(const t_cylinder *cy, const t_math_cy *mathcy, const t_ray *ray, double raydir_dot_odir)
{
	double	a;
	double	b;
	double	result;

	a = a_calculation(raydir_dot_odir);
	b = b_calculation(&mathcy->os, &ray->dir, mathcy->os_dot_odir, raydir_dot_odir);
	result = quadratic_equation(a, b, mathcy->c_factor);
	if (result != INFINITY && !is_in_height(ray, cy, result))
		result = INFINITY;
	return (result);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
double	intersect_ray_cylinder(const t_cylinder *cy, const t_math_cy *mathcy, const t_ray *ray)
{
	double	raydir_dot_odir;
	double	result;
	double	t;
	t_vec3	p;

	raydir_dot_odir = ft_dot_vec3(&ray->dir, &cy->dir);
	result = inter_infinite_cy(cy, mathcy, ray, raydir_dot_odir);
	t = intersect_ray_plane_value(mathcy->bs_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < result)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathcy->b) <= cy->r)
			result = t;
	}
	t = intersect_ray_plane_value(mathcy->ts_dot_odir, raydir_dot_odir);
	if (t != INFINITY && t < result)
	{
		p = ft_translation(&ray->s, &ray->dir, t);
		if (ft_distance_vec3(&p, &mathcy->t) <= cy->r)
			result = t;
	}
	return (result);
}

double	intersect_light_cylinder(const t_cylinder *cy, const t_ray *ray)
{
	t_math_cy	mathcy;
	double		result;

	init_math_cylinder(&ray->s, cy, &mathcy);
	result = intersect_ray_cylinder(cy, &mathcy, ray);
	return (result);
}
