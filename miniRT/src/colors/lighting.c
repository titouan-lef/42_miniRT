/// @todo header

#include "minirt.h"

static t_color	mix_color_and_lights(const t_intersec *inter,
	t_vec3 *total_light, t_vec3 *spec_effect)
{
	t_vec3	v;
	t_color	color;

	v = inter->obj->pattern.colors;
	if (inter->obj->pattern.texture.name != NULL)
		v = inter->obj->pattern.colors;
	if (inter->obj->pattern.checkerboard == 1)
		v = uv_manager(inter, v);
	v.x = v.x * total_light->x;
	v.y = v.y * total_light->y;
	v.z = v.z * total_light->z;
	v = ft_sum_vec3(&v, spec_effect);
	if (v.x > 1)
		v.x = 1;
	if (v.y > 1)
		v.y = 1;
	if (v.z > 1)
		v.z = 1;
	color = ft_vec3_to_color(&v, 255);
	return (color);
}

t_color	lighting(const t_intersec *inter, t_obj **tab_obj, t_light **tab_l,
	const t_amb *amb)
{
	t_color	c;
	t_vec3	spec_effect;
	t_vec3	total_light;
	double	cos_angle;

	c = ft_color_create(0, 0, 0, 255);
	if (inter->obj == NULL)
		return (c);
	total_light = apply_ambient(amb);
	spec_effect = ft_create_vec3(0, 0, 0);
	while (*tab_l != NULL)
	{
		cos_angle = cos_angle_light(*tab_l, &inter->soluce);
		if (cos_angle <= EPSILON || shadow(tab_obj, *tab_l, &inter->soluce.p))
		{
			++tab_l;
			continue ;
		}
		apply_diffuse(*tab_l, &total_light, cos_angle);
		apply_specular(*tab_l, &spec_effect, inter, cos_angle);
		++tab_l;
	}
	c = mix_color_and_lights(inter, &total_light, &spec_effect);
	return (c);
}
