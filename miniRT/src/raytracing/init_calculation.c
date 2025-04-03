/// @todo header

#include "minirt.h"

static void	init_calculation_sphere(t_sphere_obj *sphere, t_scene *scene)
{
	t_vec3	os;
	double	r;

	os = ft_diff_vec3(&scene->cam.pos, &sphere->sp.pos);
	r = sphere->sp.r;
	sphere->mathsp.os = os;
	sphere->mathsp.c_factor = ft_dotproduct_vec3(&os, &os) - (r * r);
}

static void	init_calculation_cylinder(t_cylinder_obj *cylinder, t_scene *scene)
{
	t_vec3	bc;

	bc = calculation_born(cylinder->cy.pos, cylinder->cy.dir, -cylinder->cy.h / 2.0);
	cylinder->mathcy.bc_o = ft_diff_vec3(&scene->cam.pos, &bc);
	cylinder->mathcy.bc_o_dot_dir = ft_dotproduct_vec3(&cylinder->mathcy.bc_o, &cylinder->cy.dir);
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
			init_calculation_sphere((t_sphere_obj *)(obj->data), scene);
		else if (obj->type == CYLINDER)
			init_calculation_cylinder((t_cylinder_obj *)(obj->data), scene);
		lst_obj = lst_obj->next;
	}
}
