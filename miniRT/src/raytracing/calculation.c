/// @todo header

#include "minirt.h"

double	length_screen(double fov)
{
	double	distance;

	distance = WIN_HW / (tan(M_PI * fov / 360.0));
	return (distance);
}

/**
 * @brief Solve equation to get the smallest factor of intersection greater
 * than or equal to 1.
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

double	min_quadratic_equation(double a, double b, double c)
{
	double	result[2];

	quadratic_equation(result, a, b, c);
	if (result[0] < result[1])
		return (result[0]);
	return (result[1]);
}
