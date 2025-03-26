/// @todo header

#include "minirt.h"

double	length_screen(double fov)
{
	double	distance;

	distance = WIN_W / (2.0 * tan(fov * M_PI / 360.0));
	return (distance);
}

/**
 * @brief Solve equation to get the smallest factor of intersection greater
 * than or equal to 1.
 * @details Solve equation ax^2 + bx + c = 0.
 * @return A factor define on [1, INFINITY[. If INFINITY is return,
 * no solution found.
 */
double	quadratic_equation(double a, double b, double c)
{
	double	t1;
	double	t2;
	double	delta;

	delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		t1 = (-b + sqrt(delta)) / (2.0 * a);
		t2 = (-b - sqrt(delta)) / (2.0 * a);
		if (t1 < 1 && t2 < 1)
			return (INFINITY);
		if (t2 < 1 || t1 < t2)
			return (t1);
		return (t2);
	}
	else if (delta == 0)
	{
		t1 = -b / (2.0 * a);
		if (t1 < 1)
			return (INFINITY);
		return (t1);
	}
	return (INFINITY);
}
