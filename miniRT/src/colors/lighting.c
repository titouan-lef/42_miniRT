/// @todo header

#include "minirt.h"
/*
static t_color	ambient(t_color obj_color, t_amb *amb, double kd)
{
	t_color	color;
	
	color = ft_scal_color(amb->color, kd * amb->lr);
	color = ft_mult_colors(obj_color, color);
	return (color);
}

t_vec3	ft_get_normal(t_vec3 c_sp, t_pixel *pixel)
{
	t_vec3	result;
	
	result = ft_scalarmult_vec3(&pixel->ray_dir, pixel->d);
	result = ft_diff_vec3(&result, &c_sp);
	result = ft_normalize_vec3(&result);
	return (result);
}

t_vec3	get_normal(t_obj *obj, t_pixel *pixel)
{
	t_vec3	result;
	
	result = ft_get_normal(((t_sphere_obj *)(obj->data))->sp.pos, pixel);
	return (result);
}


void lighting(t_intersec *intersec, t_list *lst_light, t_amb *amb)
{
	t_light	*light;
	t_color	newcolor;
	double	kd;

	kd = 1.0;
	if (intersec->obj == NULL)
		return ;
	newcolor = ambient(intersec->color, amb, kd);

	while (lst_light)
	{
		light = (t_light *)lst_light->content;
		//newcolor = diffuse(newcolor, light, pixel, kd);
		lst_light = lst_light->next;
	}
	intersec->color = newcolor;
}

*/