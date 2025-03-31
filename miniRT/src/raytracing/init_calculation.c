/// @todo header

#include "minirt.h"

static void	init_calculation_sphere(t_sphere *sphere, t_scene *scene)
{
	sphere->r = sphere->diam / 2;
	sphere->rs0 = ft_diff_vector3(scene->camera.position, sphere->position);
}

static void	init_calculation_plan(t_plan *plan, t_scene *scene)
{
	plan->rp0 = ft_diff_vector3(plan->position, scene->camera.position);
}

static void	init_calculation_cylinder(t_cylinder *cyl, t_scene *scene)
{
	cyl->r = cyl->diam / 2;
	cyl->ra2 = calculation_born(cyl->position, cyl->orientation, cyl->height / 2);
	cyl->ra1 = calculation_born(cyl->position, cyl->orientation, -cyl->height / 2);
	calculation_cyl_s(&cyl->s, cyl->ra1, cyl->ra2);
	calculation_cyl_ra0(&cyl->ra0, cyl->s, cyl->ra1, scene->camera.position);
}
/*
static void	init_calculation_cone()
{
	
}
*/

void init_calculation(t_scene *scene, t_list *lst_obj)
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
		//else if(obj->type == CONE)
		//	init_calculation_cone((t_cone*)(obj->data));
		lst_obj = lst_obj->next;
	}
}
