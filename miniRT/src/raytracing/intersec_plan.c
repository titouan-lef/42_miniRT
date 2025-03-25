/// @todo header

#include "minirt.h"

static double	a_calculation(t_vector3 a, t_vector3 d)
{
	double	result;

	result = ft_dotproduct_vector3(a, d);
	return (result);
}

static double	b_calculation(t_vector3 p, t_vector3 a, t_vector3 o)
{
	double		result;

	result = 0.0;//a suivre
	return (result);
}

static double	equation_plan(double a, double b)
{
	double	result;

	result = a / b;
	return (result);
}

double	intersect_ray_plan(t_plan plan, t_vector3 pixel, t_vector3 origin)
{
	double	a;
	double	b;
	double	result;

	a = a_calculation(plan.orientation, pixel);
	if (a == 0)
		return (INFINITY);
	b = b_calculation(plan.orientation, plan.position, origin);
	result = equation_plan(a, b);
	return (result);
}
