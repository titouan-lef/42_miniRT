/// @todo header

#include "minirt.h"

/**
 * @brief Get a factor define by ray_dir.x^2 + ray_dir.y^2 + ray_dir.z^2.
 */
static double	a_calculation(t_vector3 ray_dir)
{
	double	result;

	result = ft_dotproduct_vector3(ray_dir, ray_dir);
	return (result);
}

/**
 * @brief Get a factor define by :
 * 2*((p.x-s.x) * ray_dir.x + (p.y-s.y) * ray_dir.y + (p.z-s.z) * ray_dir.z).
 */
static double	b_calculation(t_vector3 p, t_vector3 s, t_vector3 ray_dir)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_diff_vector3(p, s);
	result = ft_dotproduct_vector3(tmp, ray_dir);
	result *= 2.0;
	return (result);
}

/**
 * @brief Get a factor define by :
 * (p.x-s.x)^2 + (p.y-s.y)^2 + (p.z-s.z)^2 - r^2.
 */
static double	c_calculation(t_vector3 p, t_vector3 s, double r)
{
	double		result;
	t_vector3	tmp;

	tmp = ft_diff_vector3(p, s);
	result = ft_dotproduct_vector3(tmp, tmp) - (r * r);
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
double	intersect_ray_sphere(t_sphere *sphere, t_vector3 ray_dir, t_vector3 p)
{
	double	a;
	double	b;
	double	c;
	double	result;

	a = a_calculation(ray_dir);
	b = b_calculation(p, sphere->position, ray_dir);
	c = c_calculation(p, sphere->position, sphere->diam / 2.0);
	result = quadratic_equation(a, b, c);
	return (result);
}
