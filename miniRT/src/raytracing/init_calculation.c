/// @todo header

#include "minirt.h"

static void	init_calculation_sphere(t_sphere *sphere, t_scene *scene)
{
	sphere->r = sphere->diam / 2.0;
	sphere->rs0 = ft_diff_vector3(scene->camera.position, sphere->position);
}

static void	init_calculation_plan(t_plan *plan, t_scene *scene)
{
	plan->rp0 = ft_diff_vector3(plan->position, scene->camera.position);
}

static void	init_calculation_cylinder(t_cylinder *cyl, t_scene *scene)
{
	t_vector3	bc;

	cyl->r = cyl->diam / 2.0;
	bc = calculation_born(cyl->position, cyl->orientation, -cyl->height / 2.0);
	cyl->bc_o = ft_diff_vector3(scene->camera.position, bc);
	cyl->bc_o_dot_dir = ft_dotproduct_vector3(cyl->bc_o, cyl->orientation);
}
/*
static void	init_calculation_cone()
{

}
//else if(obj->type == CONE)
//	init_calculation_cone((t_cone*)(obj->data));
*/

void	init_calculation(t_scene *scene, t_list *lst_obj)
{
	t_obj	*obj;

	while (lst_obj)
	{
		obj = (t_obj *)lst_obj->content;
		if (obj->type == SPHERE)
			init_calculation_sphere((t_sphere *)(obj->data), scene);
		else if (obj->type == PLAN)
			init_calculation_plan((t_plan *)(obj->data), scene);
		else if (obj->type == CYLINDER)
			init_calculation_cylinder((t_cylinder *)(obj->data), scene);
		lst_obj = lst_obj->next;
	}
}
