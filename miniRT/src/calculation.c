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
