/// @todo header

#include "minirt.h"

double	cos_angle_light(const t_light *light, const t_intersec *inter,
	const t_vec3 *n)
{
	t_vec3	light_dir;
	double	fact;

	light_dir = ft_diff_vec3(&light->pos, &inter->p);
	light_dir = ft_normalize_vec3(&light_dir);
	fact = ft_dot_vec3(&light_dir, n);
	return (fact);
}

t_color	diffuse(const t_light *light, double kd, double fact)
{
	t_color	color;

	color = ft_scal_color(light->color, fact * light->lbr * kd);
	return (color);
}

t_color	specular(const t_light *light, const t_intersec *inter, const t_vec3 *n, double kd, double fact)
{
	t_color	color;
	t_vec3	inv_light_dir;
	t_vec3	reflect_dir;
	t_vec3	inv_ray_dir;
	double	result;

	fact = 2 * fact;
	inv_light_dir = ft_diff_vec3(&inter->p, &light->pos);
	inv_light_dir = ft_normalize_vec3(&inv_light_dir);
	reflect_dir = ft_translation(&inv_light_dir, n, fact);
	reflect_dir = ft_normalize_vec3(&reflect_dir);
	inv_ray_dir = ft_scalmult_vec3(&inter->ray.dir, -1);
	result = ft_dot_vec3(&reflect_dir, &inv_ray_dir);
	if (result <= 0)
		return (ft_color_create(0, 0, 0, 255));
	result = pow(result, 2);
	color = ft_scal_color(light->color, result * light->lbr * kd);
	return (color);
}
