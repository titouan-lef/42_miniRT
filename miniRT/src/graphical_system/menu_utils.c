/// @todo header

#include "minirt.h"

void	defile(int *position, int start, int end, int moov)
{
	*position += moov;
	if (*position > end)
		*position = start;
	if (*position < start)
		*position = end;
}

void	init_menu(t_menu *menu)
{
	menu->enable = 0;
	menu->select_obj = 0;
	menu->select_l = 0;
	menu->select_data = 1;
}

t_vec3	*get_vec_pos(t_obj *obj)
{
	if (obj->type == SPHERE)
		return (&((t_sphere_obj *)(obj->data))->sp.pos);
	else if (obj->type == PLANE)
		return (&((t_plane_obj *)(obj->data))->pl.n);
	else if (obj->type == CYLINDER)
		return (&((t_cylinder_obj *)(obj->data))->cy.pos);
	else
		return (&((t_cone_obj *)(obj->data))->co.pos);
}
