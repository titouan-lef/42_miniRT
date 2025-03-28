/// @todo header

#include "minirt.h"

static double	a_calculation(t_vector3 n, t_vector3 d)
{
	double	result;

	result = ft_dotproduct_vector3(n, d);
	return (result);
}

static double	b_calculation(t_vector3 a, t_vector3 o, t_vector3 n)
{
	double		result;
	t_vector3	tmp_v1;

	tmp_v1 = ft_diff_vector3(o, a);
	result = ft_dotproduct_vector3(tmp_v1, n);
	return (result);
}

static double	equation_plan(double a, double b)
{
	double	result;

	result = b / a;
	return (result);
}

double	intersect_ray_plan(t_plan *plan, t_vector3 ray_dir, t_vector3 orig)
{
	double	a;
	double	b;
	double	result;

	a = a_calculation(plan->orientation, ray_dir);
	if (a == 0)
		return (INFINITY);
	b = b_calculation(plan->position, orig, plan->orientation);
	result = equation_plan(a, b);
	if (result < 1)
		return (INFINITY);
	return (result);
}
