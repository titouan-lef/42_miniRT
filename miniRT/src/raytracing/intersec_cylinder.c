/// @todo header

#include "minirt.h"

static double	a_calculation(t_vector3 d, t_vector3 v)
{
	double		result;
	t_vector3	tmp_v1;
	double		tmp_double;

	tmp_v1 = ft_crossproduct_vector3(d, v);
	tmp_double = ft_norm_vector3(tmp_v1);
	result = tmp_double * tmp_double;
	return (result);
}

static double	b_calculation(t_vector3 d, t_vector3 v, t_vector3 o, t_vector3 c)
{
	double		result;
	
	t_vector3	tmp_v1;
	t_vector3	tmp_v2;
	double		tmp_double;

	tmp_v1 = ft_diff_vector3(o, c);
	tmp_v1 = ft_crossproduct_vector3(tmp_v1, v);
	tmp_v2 = ft_crossproduct_vector3(d, v);
	tmp_double = ft_dotproduct_vector3(tmp_v1, tmp_v2);
	result = 2 * tmp_double;
	return (result);
}

static double	c_calculation(t_vector3 v, t_vector3 o, t_vector3 c, double r)
{
	double		result;
	t_vector3	tmp_v1;
	double		tmp_double;

	
	result = (tmp_double * tmp_double) - (r * r);
	return (result);
}

double	intersect_ray_cylinder(t_cylinder *cylinder, t_vector3 dir_ray, t_vector3 org)
{
	double	a;
	double	b;
	double	c;
	double	result;

	a = a_calculation(dir_ray, cylinder->orientation);
	b = b_calculation(dir_ray, cylinder->orientation, org, cylinder->position);
	c = c_calculation(cylinder->orientation, org, cylinder->position, cylinder->diam / 2);
	result = quadratic_equation(a, b, c);
	return (result);
}
