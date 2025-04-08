/// @todo header

#include "minirt.h"

static void	init_math_plane(const t_vec3 *ray_s, t_plane_obj *plane)
{
	plane->math_os_dot_odir = plane->pl.d + ft_dot_vec3(&plane->pl.n, ray_s);
}
/*
static void	init_calculation_cone()
{

}
//else if(obj->type == CONE)
//	init_calculation_cone((t_cone*)(obj->data));
*/

void	init_calculation(const t_vec3 *ray_s, t_list *lst_obj)
{
	t_obj	*obj;

	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		if (obj->type == SPHERE)
		{
			t_sphere_obj *sp_obj = (t_sphere_obj *)(obj->data);
			init_math_sp(ray_s, &sp_obj->sp, &sp_obj->mathsp);
		}
		else if (obj->type == CYLINDER)
		{
			t_cylinder_obj *cy_obj = (t_cylinder_obj *)(obj->data);
			init_math_cy(ray_s, &cy_obj->cy, &cy_obj->mathcy);
		}
		else if (obj->type == PLANE)
			init_math_plane(ray_s, (t_plane_obj *)(obj->data));
		lst_obj = lst_obj->next;
	}
}
