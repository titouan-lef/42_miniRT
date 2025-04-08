/// @todo header

#include "minirt.h"

static t_color	ambient(t_amb *amb, double kd)
{
	t_color	color;

	color = ft_scal_color(amb->color, kd * amb->lr);
	return (color);
}

static t_color	get_color(const t_obj *obj)
{
	int		type;
	t_color	color;

	type = obj->type;
	if (type == SPHERE)
		color = ((t_sphere_obj *)(obj->data))->color;
	else if (type == PLANE) /** @todo Place on first in if */  
		color = ((t_plane_obj *)(obj->data))->color;
	else if (type == CYLINDER)
		color = ((t_cylinder_obj *)(obj->data))->color;
	else
		color = ((t_cone_obj *)(obj->data))->color;
	return (color);
}

t_color	lighting(t_intersec *inter, t_list *lst_obj, t_list *lst_light, t_amb *amb)
{
	t_light	*light;
	t_color	spec_effect;
	t_color	total_light;
	t_color	c;
	t_vec3	n;
	double	cos_angle;
	double	kd;// a garder ?

	if (inter->obj == NULL)
	{
		c = ft_color_create(0, 0, 0, 255);
		return (c);
	}
	kd = 1;
	n = get_normal(inter);
	total_light = ambient(amb, kd);
	spec_effect = ft_color_create(0, 0, 0, 255);
	while (lst_light)
	{
		light = (t_light *)lst_light->content;
		cos_angle = cos_angle_light(light, inter, &n);
		if (cos_angle <= 0 || shadow(lst_obj, light, &inter->p))
		{
			lst_light = lst_light->next;
			continue ;
		}
		total_light = ft_sum_colors(total_light, diffuse(light, kd, cos_angle));
		spec_effect = ft_sum_colors(spec_effect, specular(light, inter, &n, kd, cos_angle));
		lst_light = lst_light->next;
	}
	c = get_color(inter->obj);
	c = ft_mult_colors(c, total_light);
	c = ft_sum_colors(c, spec_effect);
	return (c);
}
