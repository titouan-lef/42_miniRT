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

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details 
 */
double	intersect_ray_cylinder(t_cylinder *cyl, t_vector3 dir_ray)
{
	double	a;
	double	b;
	double	c;
	double	result;

	cyl->va = va_calculation(cyl->s, dir_ray);
	a = ft_dotproduct_vector3(cyl->va, cyl->va);
	b = b_calculation(cyl->ra0, cyl->va);
	c = c_calculation(cyl->ra0, cyl->r);
	result = quadratic_equation(a, b, c);
	
	return (result);
}
