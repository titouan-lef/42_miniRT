/// @todo header

#include "minirt.h"

static int	is_in_height(double t, t_vector3 ray_dir, t_vector3 cam_pos, t_cylinder *cyl)
{
	t_vector3	p;
	double		height;

	p = ft_scalarmult_vector3(ray_dir, t);
	p = ft_sum_vector3(cam_pos, p);
	p = ft_diff_vector3(p, cyl->position);
	height = ft_dotproduct_vector3(p, cyl->orientation);
	if (height < 0)
		height = -height;
	return (height <= cyl->height / 2.0);
}

static double	a_calculation(double dir_ray_dot_dir)
{
	return (1 - dir_ray_dot_dir * dir_ray_dot_dir);
}

static double	b_calculation(t_vector3 bc_o, t_vector3 dir_ray, double bc_o_dot_dir, double dir_ray_dot_dir)
{
	return (2.0 * (ft_dotproduct_vector3(bc_o, dir_ray) - bc_o_dot_dir * dir_ray_dot_dir));
}

static double	c_calculation(t_vector3 bc_o, double bc_o_dot_dir, double r)
{
	double	result;

	result = ft_dotproduct_vector3(bc_o, bc_o);
	result -= bc_o_dot_dir * bc_o_dot_dir;
	result -= r * r;
	return (result);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details
 */
double	intersect_ray_cylinder(t_cylinder *cyl, t_vector3 dir_ray, t_vector3 cam_pos)
{
	double	a;
	double	b;
	double	c;
	double	dir_ray_dot_dir;
	double	result;

	dir_ray_dot_dir = ft_dotproduct_vector3(dir_ray, cyl->orientation);
	a = a_calculation(dir_ray_dot_dir);
	b = b_calculation(cyl->bc_o, dir_ray, cyl->bc_o_dot_dir, dir_ray_dot_dir);
	c = c_calculation(cyl->bc_o, cyl->bc_o_dot_dir, cyl->r);
	result = quadratic_equation(a, b, c);
	if (result == INFINITY || !is_in_height(result, dir_ray, cam_pos, cyl))
		return (INFINITY);
	return (result);
}
