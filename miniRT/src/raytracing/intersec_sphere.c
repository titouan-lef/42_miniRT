/// @todo header

#include "minirt.h"

static double	A_calculation(t_vector3 D)
{
	double	result;
	
	result = ft_dotproduct_vector3(D, D);
	return (result);
}

static double	B_calculation(t_vector3 O, t_vector3 C, t_vector3 D)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_diff_vector3(O, C);
	tmp = ft_scalarmult_vector3(tmp, 2.0);
	result = ft_dotproduct_vector3(tmp, D);
	return (result);
}

static double	C_calculation(t_vector3 O, t_vector3 C, double r)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_diff_vector3(O, C);
	result = ft_dotproduct_vector3(tmp, tmp) - (r * r);
	return (result);
}

double	intersect_ray_sphere(t_sphere *sphere, t_vector3 pixel, t_vector3 origin)
{
	double	A;
	double	B;
	double	C;
	double result;

	A = A_calculation(pixel);
	B = B_calculation(origin, sphere->position, pixel);
	C = C_calculation(origin, sphere->position, sphere->diam);
	result = quadratic_equation(A, B, C);
	return (result);
}