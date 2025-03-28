/// @todo header

#include "minirt.h"

static double	a_calculation(t_vector3 d, t_vector3 v)
{
	double	result;
	double	tmp_d1;
	double	tmp_d2;

	tmp_d1 = ft_dotproduct_vector3(d, d);
	tmp_d2 = ft_dotproduct_vector3(d, v);
	tmp_d2 = tmp_d2 * tmp_d2;
	result = tmp_d1 - tmp_d2;
	return (result);
}

static double	b_calculation(t_vector3 d, t_vector3 v, t_vector3 o, t_vector3 c)
{
	double		result;
	t_vector3	x;
	double		tmp_v1;
	double		tmp_v2;
	double		tmp_v3;

	x = ft_diff_vector3(o, c);
	tmp_v1 = ft_dotproduct_vector3(d, x);
	tmp_v2 = ft_dotproduct_vector3(d, v);
	tmp_v3 = ft_dotproduct_vector3(x, v);
	result = 2 * (tmp_v1 - tmp_v2 * tmp_v3);
	return (result);
}

static double	c_calculation(t_vector3 v, t_vector3 o, t_vector3 c, double r)
{
	double		result;
	t_vector3	x;
	double		tmp_v1;
	double		tmp_v2;

	x = ft_diff_vector3(o, c);
	tmp_v1 = ft_dotproduct_vector3(x, x);
	tmp_v2 = ft_dotproduct_vector3(x, v);
	result = tmp_v1 - ( tmp_v2 * tmp_v2) - r * r;
	return (result);
}

/**
 * @brief Get the smallest factor of intersection greater than or equal to 1.
 * @details "greater than 1" is corresponding to the minimum distance at which
 * the object must be in order to be seen.
 * sphere equation : (x - s.x)^2 + (y - s.y)^2 + (z - s.z)^2 = r^2
 * x : p.x + ray_dir.x * t
 * y : p.y + ray_dir.y * t
 * z : p.z + ray_dir.z * t
 * After development equation become : a * t^2 + b * t + c = 0
 * @param sphere Sphere object.
 * @param ray_dir Direction vector of the ray (vector from camera to pixel).
 * @param p A start point of the ray (camera position).
 * @return A factor define on [1, INFINITY[. If INFINITY is return,
 * no intersections found.
 */
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
