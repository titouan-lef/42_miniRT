/// @todo header

#include "minirt.h"
/*
t_color diffuse(t_color obj_color, t_light *light, t_pixel *pixel, double kd)
{
	t_color color;
	t_vec3	l_dir;
	double	fact;
	
	l_dir = ft_scalarmult_vec3(&pixel->ray_dir, pixel->d);
	l_dir = ft_diff_vec3(&light->pos, &l_dir);
	fact = ft_dotproduct_vec3(&light->pos, &pixel->normal);
	fact = fact / pixel->d;
	//printf("k = %f, cos = %f, lbr = %f\n", kd, fact, light->lbr);
	color = ft_scal_color(light->color, fact * light->lbr * kd);
	//printf("ncolor %d,%d,%d\n", color.r, color.g, color.b);
	//exit(1);
	color = ft_sum_colors(obj_color, color);
	return (color);
}
*/
