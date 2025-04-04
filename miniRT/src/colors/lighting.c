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
	else if (type == PLANE)/** @todo Place on first in if */  
		color = ((t_plane_obj *)(obj->data))->color;
	else if (type == CYLINDER)
		color = ((t_cylinder_obj *)(obj->data))->color;
	else
		color = ((t_cone_obj *)(obj->data))->color;
	return (color);
}

static t_vec3 get_normal(t_intersec *inter)
{
	t_vec3		n;
	t_sphere	sp;

	sp = ((t_sphere_obj *)inter->obj->data)->sp;
	n = ft_diff_vec3(&inter->p, &sp.pos);
	n = ft_normalize_vec3(&n);
	return (n);
}

t_color lighting(t_intersec *inter, t_list *lst_light, t_amb *amb)
{
	double	kd;// a garder ?
	t_light	*light;
	t_color	c;
	t_color	total_light;
	t_vec3	n;

	if (inter->obj == NULL)
	{
		c = ft_color_create(0, 0, 0, 255);
		return (c);
	}
	kd = 1;
	total_light = ambient(amb, kd);
	n = get_normal(inter);
	while (lst_light)
	{
		light = (t_light *)lst_light->content;
		total_light = ft_sum_colors(total_light, diffuse(light, inter, &n, kd));
		lst_light = lst_light->next;
	}
	c = get_color(inter->obj);
	c = ft_mult_colors(c, total_light);
	return (c);
}
