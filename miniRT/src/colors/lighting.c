/// @todo header

#include "minirt.h"

t_color	ambient(t_color obj_color, t_amb *amb)
{
	t_color	newcolor;

	(void)obj_color;
	newcolor = ft_scalprod_color(amb->color, amb->lr);
	//newcolor = ft_sum_colors(obj_color, newcolor);
	return (newcolor);
}

t_color	diffuse(t_pixel *pixel, t_light *light, t_vector3 normal)
{
	double	kd;
	t_color	newcolor;
	t_vector3	l;

	l = ft_diff_vector3(light->pos,ft_scalarmult_vector3(pixel->ray_dir, pixel->d));
	l = ft_scalarmult_vector3(l, -1.0);
	
	kd = 0.5;
	kd = kd * light->lbr * ft_dotproduct_vector3(l, normal);
	newcolor = ft_scalprod_color(light->color, kd);
	return (newcolor);
}
	
/*
t_color	specular()
{
	
}

t_vector3	ft_get_obj_dir(t_obj *obj)
{
	if (obj->type == PLAN)
	return(((t_plan *)(obj->data))->orientation);
	else if (obj->type == CYLINDER)
	return(((t_cylinder *)(obj->data))->orientation);
	else
	return(((t_cone *)(obj->data))->orientation);
}

t_vector3	normal_of_inter(t_pixel *pixel)
{
	t_vector3	normal;
	
	if (pixel->obj->type == SPHERE)
	{
		normal = ft_diff_vector3(((t_sphere *)(pixel->obj->data))->position, ft_scalarmult_vector3(pixel->ray_dir, pixel->d));
		printf("%f | %f | %f \n", normal.x , normal.y, normal.z);
	}
	else
	{
		normal = ft_crossproduct_vector3(ft_get_obj_dir(pixel->obj), pixel->ray_dir);
	}
	return (normal);
}
*/

void lighting(t_pixel *pixel, t_list *lst_light, t_amb *amb)
{
	t_light		*light;
	t_color		newcolor;
	//t_vector3	normal;
	
	if (pixel->obj == NULL)
		return ;
	newcolor = ambient(pixel->color, amb);
	//normal = normal_of_inter(pixel);
	while (lst_light)
	{
		light = (t_light *)lst_light->content;
		//newcolor = ft_sum_colors(newcolor, diffuse(pixel, light, normal));
		//newcolor = ft_sum_colors(newcolor, specular());
		lst_light = lst_light->next;
	}
	pixel->color = newcolor;
}

