/// @todo header

#include "minirt.h"

static void	init_calculation_sp(const t_vec3 *ray_s, const t_obj *obj)
{
	t_sphere_obj	*sp_obj;

	sp_obj = (t_sphere_obj *)(obj->data);
	init_math_sp(ray_s, &sp_obj->sp, &sp_obj->mathsp);
}

static void	init_calculation_pl(const t_vec3 *ray_s, const t_obj *obj)
{
	t_plane_obj	*pl_obj;

	pl_obj = (t_plane_obj *)(obj->data);
	init_math_pl(ray_s, &pl_obj->pl, &pl_obj->math_os_dot_odir);
}

static void	init_calculation_cy(const t_vec3 *ray_s, const t_obj *obj)
{
	t_cylinder_obj	*cy_obj;

	cy_obj = (t_cylinder_obj *)(obj->data);
	init_math_cy(ray_s, &cy_obj->cy, &cy_obj->mathcy);
}

static void	init_calculation_co(const t_vec3 *ray_s, const t_obj *obj)
{
	t_cone_obj	*co_obj;

	co_obj = (t_cone_obj *)(obj->data);
	init_math_co(ray_s, &co_obj->co, &co_obj->mathco);
}

void	init_calculation(const t_vec3 *ray_s, t_list *lst_obj)
{
	t_obj	*obj;

	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		if (obj->type == SPHERE)
			init_calculation_sp(ray_s, obj);
		else if (obj->type == CYLINDER)
			init_calculation_cy(ray_s, obj);
		else if (obj->type == PLANE)
			init_calculation_pl(ray_s, obj);
		else if (obj->type == CONE)
			init_calculation_co(ray_s, obj);
		lst_obj = lst_obj->next;
	}
}
