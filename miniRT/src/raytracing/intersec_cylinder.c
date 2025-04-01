/// @todo header

#include "minirt.h"

static t_vector3	va_calculation(t_vector3 s, t_vector3 v)
{
	t_vector3	va;

	va = ft_crossproduct_vector3(s, v);
	va = ft_crossproduct_vector3(va, s);
	return (va);
}

static double	b_calculation(t_vector3 ra0, t_vector3 va)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_scalarmult_vector3(ra0, 2.0);
	result = ft_dotproduct_vector3(tmp, va);
	return (result);
}

static double	c_calculation(t_vector3 ra0, double r)
{
	double		result;

	result = ft_dotproduct_vector3(ra0, ra0) - r * r;
	return (result);
}
/*
static double	border_cylinder(double t, t_cylinder *cyl, 
t_vector3 cam_pos, t_vector3 dir_ray)
{
	t_vector3	ray;
	t_vector3	tmp;
	double		result;
	
	ray =  ft_scalarmult_vector3(dir_ray, t);
	ray = 	ft_sum_vector3(cam_pos, ray);
	tmp = ft_diff_vector3(ray, cyl->ra1);
	result = ft_dotproduct_vector3(ray, cyl->s);
	if (result < 0)
	return (INFINITY);
	tmp = ft_diff_vector3(ray, cyl->ra2);
	result = ft_dotproduct_vector3(ray, cyl->s);
	if (result > 0)
	return (INFINITY);
	return (t);
}
*/

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details 
 */
double	intersect_ray_cylinder(t_cylinder *cyl, t_vector3 dir_ray,
			t_vector3 cam_pos)
{
	double	a;
	double	b;
	double	c;
	double	result;

	(void)cam_pos;
	cyl->va = va_calculation(cyl->s, dir_ray);
	a = ft_dotproduct_vector3(cyl->va, cyl->va);
	b = b_calculation(cyl->ra0, cyl->va);
	c = c_calculation(cyl->ra0, cyl->r);
	result = quadratic_equation(a, b, c);
	return (result);
}
//result = border_cylinder(result, cyl, cam_pos, dir_ray);
