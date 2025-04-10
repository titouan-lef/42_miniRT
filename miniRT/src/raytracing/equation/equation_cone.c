/// @todo header

#include "minirt.h"

static double	a_calculation(double angle_factor, double raydir_dot_odir)
{
	return (1 - angle_factor * raydir_dot_odir * raydir_dot_odir);
}

static double	b_calculation(const t_math_co *mathco, const t_vec3 *raydir,
	double raydir_dot_odir)
{
	double	dot;
	double	product;

	dot = ft_dot_vec3(&mathco->bs, raydir);
	product = mathco->angle_factor * mathco->bs_dot_odir * raydir_dot_odir;
	return (2.0 * (dot - product));
}

static double	c_calculation(const t_vec3 *bs, double bs_dot_odir,
	double angle_factor)
{
	double	dot;

	dot = ft_dot_vec3(bs, bs);
	return (dot - angle_factor * bs_dot_odir * bs_dot_odir);
}

double	solve_eq_co(const t_math_co *mathco, const t_ray *ray,
	double raydir_dot_odir)
{
	double	result;
	double	a;
	double	b;

	a = a_calculation(mathco->angle_factor, raydir_dot_odir);
	b = b_calculation(mathco, &ray->dir, raydir_dot_odir);
	result = quadratic_equation(a, b, mathco->c_factor);
	return (result);
}

void	init_math_co(const t_vec3 *ray_s, const t_cone *co, t_math_co *mathco)
{
	t_vec3	b;
	t_vec3	bs;
	t_vec3	tmp;
	double	bs_dot_odir;
	double	angle_factor;

	tmp = ft_scalmult_vec3(&co->dir, co->h / 2.0);
	b = ft_diff_vec3(&co->pos, &tmp);
	bs = ft_diff_vec3(ray_s, &b);
	bs_dot_odir = ft_dot_vec3(&bs, &co->dir);
	angle_factor = co->r / co->h;
	angle_factor = 1 + angle_factor * angle_factor;
	mathco->b = b;
	mathco->bs = bs;
	mathco->bs_dot_odir = bs_dot_odir;
	mathco->angle_factor = angle_factor;
	mathco->c_factor = c_calculation(&bs, bs_dot_odir, angle_factor);
	mathco->t = ft_sum_vec3(&co->pos, &tmp);
	mathco->ts_dot_odir = bs_dot_odir - co->h;
}
