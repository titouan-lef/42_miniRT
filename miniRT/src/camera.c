/// @todo header

#include "minirt.h"

static double	distance_screen(double fov)
{
	double	distance;
	
	distance = WIN_WIDTH / (2 * tan( fov / 2));
	return (distance);
}

static void	norm_vecteur(t_vector3 *vector)
{
	double	norm;

	norm = sqrt(exp2(vector->x) + exp2(vector->y) + exp2(vector->z));
	vector->x = vector->x / norm;
	vector->y = vector->y / norm;
	vector->z = vector->z / norm;
}

static t_vector3 colors_manipulation(t_vector3 *first_colors, t_vector3 *second_colors)
{
	t_vector3	new_colors;

	new_colors.x = first_colors->x + second_colors->x;
	if (new_colors.x > 255)
		new_colors.x = 255;
	new_colors.y = first_colors->y + second_colors->y;
	if (new_colors.y > 255)
		new_colors.y = 255;
	new_colors.z = first_colors->z + second_colors->z;
	if (new_colors.z > 255)
		new_colors.z = 255;
	return (new_colors);
}
void	ray_lauch_test(void)
{
	double x;
	double y;
	double distance;
	double fov;

	distance = distance_screen(fov);
	x = -1 * WIN_WIDTH / 2;
	while (x < WIN_WIDTH / 2)
	{
		y = -1 * WIN_HEIGHT / 2;
		while (y < WIN_HEIGHT / 2)
		{
			lauch_ray();
			y++;
		}
		x++;
	}
}
