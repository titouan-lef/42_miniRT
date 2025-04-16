/// @todo header

#include "minirt.h"

static t_color	ambient(const t_amb *amb)
{
	t_color	color;

	color = ft_scal_color(amb->color, KD * amb->lr);
	return (color);
}

static t_color	get_color(const t_obj *obj)
{
	int		type;
	t_color	color;

	type = obj->type;
	if (type == SPHERE)
		color = ((t_sphere_obj *)(obj->data))->color;
	else if (type == PLANE)
		color = ((t_plane_obj *)(obj->data))->color;
	else if (type == CYLINDER)
		color = ((t_cylinder_obj *)(obj->data))->color;
	else
		color = ((t_cone_obj *)(obj->data))->color;
	return (color);
}

static t_color	mix_color_and_lights(const t_intersec *inter,
	t_color *total_light, t_color *spec_effect)
{
	t_color	c;

	c = get_color(inter->obj);
	c = ft_mult_colors(c, *total_light);
	c = ft_sum_colors(c, *spec_effect);
	return (c);
}

t_color	lighting(const t_intersec *inter, t_obj **tab_obj,
	t_light **tab_l, const t_amb *amb)
{
	t_color	spec_effect;
	t_color	total_light;
	t_color	c;
	double	cos_angle;

	c = ft_color_create(0, 0, 0, 255);
	if (inter->obj == NULL)
		return (c);
	spec_effect = c;
	total_light = ambient(amb);
	while (*tab_l != NULL)
	{
		cos_angle = cos_angle_light(*tab_l, &inter->soluce);
		if (cos_angle <= 0.0 || shadow(tab_obj, *tab_l, &inter->soluce.p))
		{
			++tab_l;
			continue ;
		}
		total_light = ft_sum_colors(total_light, diffuse(*tab_l, cos_angle));
		spec_effect = ft_sum_colors(spec_effect, specular(*tab_l, inter,
					&inter->soluce.n, cos_angle));
		++tab_l;
	}
	c = mix_color_and_lights(inter, &total_light, &spec_effect);
	return (c);
}
