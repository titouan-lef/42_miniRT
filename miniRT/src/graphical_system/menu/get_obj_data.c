/// @todo header

#include "minirt.h"

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

t_vec3	*get_vec_dir(t_obj *obj)
{
	if (obj->type == PLANE)
		return (&((t_plane_obj *)(obj->data))->pl.n);
	else if (obj->type == CYLINDER)
		return (&((t_cylinder_obj *)(obj->data))->cy.dir);
	else if (obj->type == CONE)
		return (&((t_cone_obj *)(obj->data))->co.dir);
	return (NULL);
}

double	*get_obj_diam(t_obj *obj)
{
	if (obj->type == SPHERE)
		return (&((t_sphere_obj *)(obj->data))->sp.r);
	else if (obj->type == CYLINDER)
		return (&((t_cylinder_obj *)(obj->data))->cy.r);
	else if (obj->type == CONE)
		return (&((t_cone_obj *)(obj->data))->co.r);
	return (NULL);
}

double	*get_obj_height(t_obj *obj)
{
	if (obj->type == CYLINDER)
		return (&((t_cylinder_obj *)(obj->data))->cy.hh);
	else if (obj->type == CONE)
		return (&((t_cone_obj *)(obj->data))->co.h);
	return (NULL);
}

int	get_range(t_obj *obj)
{
	if (obj->type == SPHERE)
		return (4);
	else if (obj->type == PLANE)
		return (6);
	else
		return (8);
}
