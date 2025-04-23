/// @todo header

#include "minirt.h"

double	cos_angle_light(const t_light *l, const t_soluce *soluce)
{
	t_vec3	pl;
	double	fact;

	pl = ft_create_normalized_vec3(&soluce->p, &l->pos);
	fact = ft_dot_vec3(&pl, &soluce->n);
	return (fact);
}

t_vec3	apply_ambient(const t_amb *amb)
{
	t_vec3	color;

	color = ft_scalmult_vec3(&amb->color, KD * amb->lr);
	return (color);
}

void	apply_diffuse(const t_light *light, t_vec3 *diffuse, double fact)
{
	t_vec3	color;

	color = ft_scalmult_vec3(&light->color, fact * light->lbr * KD);
	*diffuse = ft_sum_vec3(diffuse, &color);
}

void	apply_specular(const t_light *light, t_vec3 *specular,
	const t_intersec *inter, double fact)
{
	t_vec3	color;
	t_vec3	lp;
	t_vec3	reflect_dir;
	t_vec3	inv_ray_dir;
	double	brightness;

	lp = ft_create_normalized_vec3(&light->pos, &inter->soluce.p);
	reflect_dir = ft_translation_vec3(&lp, &inter->soluce.n, 2 * fact);
	reflect_dir = ft_normalize_vec3(&reflect_dir);
	inv_ray_dir = ft_scalmult_vec3(&inter->ray.dir, -1);
	brightness = ft_dot_vec3(&reflect_dir, &inv_ray_dir);
	if (brightness <= 0)
		return ;
	brightness = pow(brightness, 2);
	color = ft_scalmult_vec3(&light->color, brightness * light->lbr * KD);
	*specular = ft_sum_vec3(specular, &color);
}
