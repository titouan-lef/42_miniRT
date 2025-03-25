/// @todo header

#include "minirt.h"

static double	A_calculation(t_vector3 a, t_vector3 D)
{
	double	result;
	
	result = ft_dotproduct_vector3(a, D);
	return (result);
}

static double	B_calculation(t_vector3 P, t_vector3 a, t_vector3 O)
{
	double		result;
	
	result = 0.0; //a suivre
	return (result);
}

static double	equation_plan(double A, double B)
{
	double	result;

	result = A / B;
	return (result);
}

double	intersect_ray_plan(t_plan plan, t_vector3 pixel, t_vector3 origin)
{
	double	A;
	double	B;
	double	result;

	A = A_calculation(plan.orientation, pixel);
	if (A == 0)
		return (INFINITY);
	B = B_calculation(plan.orientation, plan.position, origin);
	result = equation_plan(A, B);
	return (result);
}