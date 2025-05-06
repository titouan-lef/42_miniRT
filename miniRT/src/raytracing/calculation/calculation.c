/// @todo header

#include "minirt.h"

/**
 * @brief Get the vector after a base change.
 */
t_vec3	change_base(const t_base *base, const t_vec3 *v)
{
	t_vec3	new;

	new.x = base->e1.x * v->x + base->e2.x * v->y + base->e3.x * v->z;
	new.y = base->e1.y * v->x + base->e2.y * v->y + base->e3.y * v->z;
	new.z = base->e1.z * v->x + base->e2.z * v->y + base->e3.z * v->z;
	return (new);
}

/**
 * @brief Get the distance between viewport and camera.
 * @param fov Field of view in degrees.
 * @return A distance greater than 0.
 * @warning Fov less than 1 will be set on 1, and fov greater than 180 will be
 * set on 179.
 */
double	length_screen(int fov)
{
	double	distance;

	if (fov < 1)
		fov = 1;
	else if (fov > 179)
		fov = 179;
	distance = WIN_HW / (tan(fov / 360.0 * M_PI));
	return (distance);
}

/**
 * @brief Solve equation to get the 2 factors of intersection greater than or
 * equal to 1.
 * @details Solve equation ax^2 + bx + c = 0.
 * @return A factor define on [1, INFINITY[. If INFINITY is return,
 * no solution found.
 */
void	quadratic_equation(double result[2], double a, double b, double c)
{
	double	delta;

	result[0] = INFINITY;
	result[1] = INFINITY;
	if (a == 0)
		return ;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return ;
	if (delta > 0)
	{
		result[0] = (-b + sqrt(delta)) / (2.0 * a);
		result[1] = (-b - sqrt(delta)) / (2.0 * a);
		if (result[1] < 1)
			result[1] = INFINITY;
	}
	else
		result[0] = -b / (2.0 * a);
	if (result[0] < 1)
		result[0] = INFINITY;
}

/**
 * @brief Solve equation to get the smallest factor of intersection greater
 * than or equal to 1.
 * @details Solve equation ax^2 + bx + c = 0.
 * @return A factor define on [1, INFINITY[. If INFINITY is return,
 * no solution found.
 */
double	min_quadratic_equation(double a, double b, double c)
{
	double	result[2];

	quadratic_equation(result, a, b, c);
	if (result[0] < result[1])
		return (result[0]);
	return (result[1]);
}
