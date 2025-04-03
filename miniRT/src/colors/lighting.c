/// @todo header

#include "minirt.h"

t_color	ambient(t_color obj_color, t_amb *amb, double kd)
{
	t_color	color;

	color = ft_multipl_colors(obj_color, amb->color);
	color = ft_scalprod_color(color, kd * amb->lr);

	return (color);
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
		lst_light = lst_light->next;
	}
	intersec->color = newcolor;
}
