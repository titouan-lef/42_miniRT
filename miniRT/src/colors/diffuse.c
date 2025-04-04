/// @todo header

#include "minirt.h"

t_color diffuse(t_light *light,t_intersec *inter, t_vec3 *n, double kd)
{
	t_color color;
	t_vec3	light_dir;
	double	fact;

	light_dir = ft_diff_vec3(&light->pos, &inter->p);
	light_dir = ft_normalize_vec3(&light_dir);
	fact = ft_dot_vec3(&light_dir, n);
	color = ft_scal_color(light->color, fact * light->lbr * kd);
	return (color);
}

