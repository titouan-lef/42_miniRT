/// @todo header

#include "minirt.h"

double	length_screen(double fov)
{
	double	distance;

	distance = WIN_W / (2.0 * tan((fov * M_PI / 180.0) / 2.0));
	return (distance);
}

double	quadratic_equation(double a, double b, double c)
{
	double	t1;
	double	t2;
	double	delta;

	delta = (b * b) - (4 * a * c);
	if (delta > 0)
	{
		t1 = (((-1.0 * b) + sqrt(delta)) / (2 * a));
		t2 = (((-1.0 * b) - sqrt(delta)) / (2 * a));
		if (t1 < t2)
			return (t1);
		return (t2);
	}
	else if (delta == 0)
	{
		t1 = (((-1.0 * b) + sqrt(delta)) / (2 * a));
		return (t1);
	}
	return (INFINITY);
}
