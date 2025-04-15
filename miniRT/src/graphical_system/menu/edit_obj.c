/// @todo header

#include "minirt.h"

static void	obj_resize(double *r, int sign)
{
	if (*r - DIST < 0 && sign < 0)
		*r = 0;
	else
		*r += DIST * sign;
}

void	edit_cone(int sign, t_menu *menu, t_cone_obj *cone)
{
	t_vec3	r_axis;

	if (menu->select_data == 1)
		cone->co.pos.x += DIST * sign;
	else if (menu->select_data == 2)
		cone->co.pos.y += DIST * sign;
	else if (menu->select_data == 3)
		cone->co.pos.z += DIST * sign;
	else if (menu->select_data > 3 && menu->select_data < 7)
	{
		if (menu->select_data == 4)
			r_axis = ft_create_vec3(1, 0, 0);
		else if (menu->select_data == 5)
			r_axis = ft_create_vec3(0, 1, 0);
		else if (menu->select_data == 6)
			r_axis = ft_create_vec3(0, 0, 1);
		cone->co.dir = ft_rotation_quat(&cone->co.dir, M_PI / 90 * sign, &r_axis);
	}
	else if (menu->select_data == 7)
		obj_resize(&cone->co.h, sign);
	else if (menu->select_data == 8)
		obj_resize(&cone->co.r, sign);
}

void	edit_cylinder(int sign, t_menu *menu, t_cylinder_obj *cylinder)
{
	t_vec3	r_axis;

	if (menu->select_data == 1)
		cylinder->cy.pos.x += DIST * sign;
	else if (menu->select_data == 2)
		cylinder->cy.pos.y += DIST * sign;
	else if (menu->select_data == 3)
		cylinder->cy.pos.z += DIST * sign;
	else if (menu->select_data > 3 && menu->select_data < 7)
	{
		if (menu->select_data == 4)
			r_axis = ft_create_vec3(1, 0, 0);
		else if (menu->select_data == 5)
			r_axis = ft_create_vec3(0, 1, 0);
		else if (menu->select_data == 6)
			r_axis = ft_create_vec3(0, 0, 1);
		cylinder->cy.dir = ft_rotation_quat(&cylinder->cy.dir, M_PI / 90 * sign, &r_axis);
	}
	else if (menu->select_data == 7)
		obj_resize(&cylinder->cy.r, sign);
	else if (menu->select_data == 8)
		obj_resize(&cylinder->cy.hh, sign);
}

void	edit_plane(int sign, t_menu *menu, t_plane_obj *plane)
{
	t_vec3	r_axis;

	if (menu->select_data == 1)
		plane->pl.d += DIST * sign;
	else
	{
		if (menu->select_data == 2)
			r_axis = ft_create_vec3(1, 0, 0);
		else if (menu->select_data == 3)
			r_axis = ft_create_vec3(0, 1, 0);
		else if (menu->select_data == 4)
			r_axis = ft_create_vec3(0, 0, 1);
		plane->pl.n = ft_rotation_quat(&plane->pl.n, M_PI / 22.5 * sign, &r_axis);
	}
}

/**
 * @brief modifi
 */
void	edit_sphere(int sign, t_menu *menu, t_sphere_obj *sphere)
{
	if (menu->select_data == 1)
		sphere->sp.pos.x += DIST * sign;
	else if (menu->select_data == 2)
		sphere->sp.pos.y += DIST * sign;
	else if (menu->select_data == 3)
		sphere->sp.pos.z += DIST * sign;
	else if (menu->select_data == 4)
		obj_resize(&sphere->sp.r, sign);
}
