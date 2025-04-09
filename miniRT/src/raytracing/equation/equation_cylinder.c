/// @todo header

#include "minirt.h"

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

static double	c_calculation(const t_vec3 *os, double os_dot_odir, double r)
{
	double	dot;

	dot = ft_dot_vec3(os, os);
	return (dot - os_dot_odir * os_dot_odir - r * r);
}

double	solve_eq_cy(const t_math_cy *mathcy, const t_ray *ray, double raydir_dot_odir)
{
	double	result;
	double	a;
	double	b;

	a = a_calculation(raydir_dot_odir);
	b = b_calculation(&mathcy->os, &ray->dir, mathcy->os_dot_odir, raydir_dot_odir);
	result = quadratic_equation(a, b, mathcy->c_factor);
	return (result);
}

void	init_math_cy(const t_vec3 *ray_s, const t_cylinder *cy, t_math_cy *mathcy)
{
	t_vec3	os;
	double	os_dot_odir;
	t_vec3	tmp;

	os = ft_diff_vec3(ray_s, &cy->pos);
	os_dot_odir = ft_dot_vec3(&os, &cy->dir);
	tmp = ft_scalmult_vec3(&cy->dir, cy->hh);
	mathcy->os = os;
	mathcy->os_dot_odir = os_dot_odir;
	mathcy->c_factor = c_calculation(&os, os_dot_odir, cy->r);
	mathcy->b = ft_diff_vec3(&cy->pos, &tmp);
	mathcy->t = ft_sum_vec3(&cy->pos, &tmp);
	mathcy->bs_dot_odir = os_dot_odir + cy->hh;
	mathcy->ts_dot_odir = os_dot_odir - cy->hh;
}
