/// @todo header

#include "minirt.h"

t_color	ambient_colors(t_color obj_color, t_ambient ambient)
{
	t_color	newcolor;

	newcolor = ft_scalprod_color(ambient.color, ambient.lr);
	newcolor = ft_multipl_colors(newcolor, obj_color);
	return (newcolor);
}
/*
t_color light_colors(t_color color, t_list light)
{
	
}
*/