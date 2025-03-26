/// @todo header

#include "minirt.h"

/**
 * @brief 
 */
static double	a_calculation(t_vector3 d)
{
	double	result;

	result = ft_dotproduct_vector3(d, d);
	return (result);
}

/**
 * @brief 
 */
static double	b_calculation(t_vector3 o, t_vector3 c, t_vector3 d)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_diff_vector3(o, c);
	tmp = ft_scalarmult_vector3(tmp, 2.0);
	result = ft_dotproduct_vector3(tmp, d);
	return (result);
}

/**
 * @brief 
 */
static double	c_calculation(t_vector3 o, t_vector3 c, double r)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_diff_vector3(o, c);
	result = ft_dotproduct_vector3(tmp, tmp) - (r * r);
	return (result);
}

/**
 * @param org Ray origin (camera position).
 */
double	intersect_ray_sphere(t_sphere *sphere, t_vector3 dir_ray, t_vector3 org)
{
	double	a;
	double	b;
	double	c;
	double	result;

	a = a_calculation(dir_ray);
	b = b_calculation(org, sphere->position, dir_ray);
	c = c_calculation(org, sphere->position, sphere->diam);
	result = quadratic_equation(a, b, c);
	return (result);
}
