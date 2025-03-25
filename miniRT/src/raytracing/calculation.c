/// @todo header

#include "minirt.h"

double	length_screen(double fov)
{
	double	distance;
	
	distance = WIN_WIDTH / (2.0 * tan( (fov * M_PI / 180.0)/ 2.0));
	return (distance);
}

void	norm_vecteur(t_vector3 *vector)
{
	double	norm;
	double	x2;
	double	y2;
	double	z2;

	x2 = (vector->x * vector->x);
	y2 = (vector->y * vector->y);
	z2 = (vector->z * vector->z);
	norm = sqrt(x2 + y2 + z2);
	vector->x = vector->x / norm;
	vector->y = vector->y / norm;
	vector->z = vector->z / norm;
}

double	quadratic_equation(double A, double B, double C)
{
	double	t1;
	double	t2;
	double	delta;


	delta = (B * B) - (4 * A * C);
	if (delta > 0)
	{
		t1 = (((-1.0 *B) + sqrt(delta)) / (2 * A));
		t2 = (((-1.0 *B) - sqrt(delta)) / (2 * A));
		if (t1 < t2)
			return (t1);
		return (t2);
	}
	else if (delta == 0)
	{
		t1 = (((-1.0 *B) + sqrt(delta)) / (2 * A));
		return (t1);
	}
	return (INFINITY);
}
