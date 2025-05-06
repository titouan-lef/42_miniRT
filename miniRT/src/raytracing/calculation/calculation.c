/// @todo header

#include "minirt.h"

/**
 * @brief Get the distance between viewport and camera.
 * @param fov Define on [0, 180].
 * @warning Fov equals to 0 will be define on 1. 
 */
double	length_screen(int fov)
{
	double	distance;

	if (fov == 0)
		fov = 1;
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
