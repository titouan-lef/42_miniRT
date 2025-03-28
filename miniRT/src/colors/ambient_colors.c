/// @todo header

#include "minirt.h"

t_color	ambient_colors(t_color obj_color, t_ambient ambient)
{
	t_color	newcolor;
	int	diviseur;
	
	diviseur = 1.0 / ambient.lr;

	(void)obj_color;
	newcolor.r = ambient.color.r /diviseur;
	newcolor.g = ambient.color.g /diviseur;
	newcolor.b = ambient.color.b /diviseur;
	newcolor.r += obj_color.r;
	newcolor.g += obj_color.g;
	newcolor.b += obj_color.b;
	return (newcolor);
}

t_color light_colors(t_color color, t_list light)
{
	
}