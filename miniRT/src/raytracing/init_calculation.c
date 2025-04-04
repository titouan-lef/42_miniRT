/// @todo header

#include "minirt.h"

static void	init_calculation_sphere(const t_vec3 *ray_s, t_sphere_obj *sphere)
{
	t_vec3	os;
	double	r;

	os = ft_diff_vec3(ray_s, &sphere->sp.pos);
	r = sphere->sp.r;
	sphere->mathsp.os = os;
	sphere->mathsp.c_factor = ft_dot_vec3(&os, &os) - r * r;
}

static void	init_calculation_cylinder(const t_vec3 *ray_s, t_cylinder_obj *cy_obj)
{
	t_vec3	os;
	double	r;
	double	os_dot_odir;
	t_vec3	tmp;

	os = ft_diff_vec3(ray_s, &cy_obj->cy.pos);
	r = cy_obj->cy.r;
	os_dot_odir = ft_dot_vec3(&os, &cy_obj->cy.dir);
	tmp = ft_scalmult_vec3(&cy_obj->cy.dir, cy_obj->cy.h / 2.0);
	cy_obj->mathcy.os = os;
	cy_obj->mathcy.os_dot_odir = os_dot_odir;
	cy_obj->mathcy.c_factor = ft_dot_vec3(&os, &os) - os_dot_odir * os_dot_odir - r * r;
	cy_obj->mathcy.bottom = ft_diff_vec3(&cy_obj->cy.pos, &tmp);
	cy_obj->mathcy.top = ft_sum_vec3(&cy_obj->cy.pos, &tmp);
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
			init_calculation_sphere(ray_s, (t_sphere_obj *)(obj->data));
		else if (obj->type == CYLINDER)
			init_calculation_cylinder(ray_s, (t_cylinder_obj *)(obj->data));
		lst_obj = lst_obj->next;
	}
}
