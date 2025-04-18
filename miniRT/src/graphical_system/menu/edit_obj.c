/// @todo header

#include "minirt.h"

static void	obj_resize(double *r, int *sign)
{
	if (*r - DIST < 0 && *sign < 0)
		*r = 0;
	else
		*r += DIST * *sign;
}

void	edit_cone(int *sign, t_menu *menu, t_cone_obj *cone)
{
	if (menu->select_data == 1)
		cone->co.pos.x += DIST * *sign;
	else if (menu->select_data == 2)
		cone->co.pos.y += DIST * *sign;
	else if (menu->select_data == 3)
		cone->co.pos.z += DIST * *sign;
	else if (menu->select_data > 3 && menu->select_data < 7)
	{
		if (menu->select_data == 4)
			rotation_on_right(&cone->co.right,
				&cone->co.up, &cone->co.dir, sign);
		else if (menu->select_data == 5)
			rotation_on_up(&cone->co.right, &cone->co.up,
				&cone->co.dir, sign);
		else if (menu->select_data == 6)
			rotation_on_forward(&cone->co.right,
				&cone->co.up, &cone->co.dir, sign);
	}
	else if (menu->select_data == 7)
		obj_resize(&cone->co.h, sign);
	else if (menu->select_data == 8)
		obj_resize(&cone->co.r, sign);
}

void	edit_cylinder(int *sign, t_menu *menu, t_cylinder_obj *cylinder)
{
	if (menu->select_data == 1)
		cylinder->cy.pos.x += DIST * *sign;
	else if (menu->select_data == 2)
		cylinder->cy.pos.y += DIST * *sign;
	else if (menu->select_data == 3)
		cylinder->cy.pos.z += DIST * *sign;
	else if (menu->select_data > 3 && menu->select_data < 7)
	{
		if (menu->select_data == 4)
			rotation_on_right(&cylinder->cy.right,
				&cylinder->cy.up, &cylinder->cy.dir, sign);
		else if (menu->select_data == 5)
			rotation_on_up(&cylinder->cy.right,
				&cylinder->cy.up, &cylinder->cy.dir, sign);
		else if (menu->select_data == 6)
			rotation_on_forward(&cylinder->cy.right,
				&cylinder->cy.up, &cylinder->cy.dir, sign);
	}
	else if (menu->select_data == 7)
		obj_resize(&cylinder->cy.r, sign);
	else if (menu->select_data == 8)
		obj_resize(&cylinder->cy.hh, sign);
}

void	edit_plane(int *sign, t_menu *menu, t_plane_obj *plane)
{
	if (menu->select_data == 1)
		plane->pl.d += DIST * *sign;
	else
	{
		if (menu->select_data == 2)
			rotation_on_right(&plane->right, &plane->up, &plane->pl.n, sign);
		else if (menu->select_data == 3)
			rotation_on_up(&plane->right, &plane->up, &plane->pl.n, sign);
		else if (menu->select_data == 4)
			rotation_on_forward(&plane->right, &plane->up, &plane->pl.n, sign);
	}
}

/**
 * @brief modifi
 */
void	edit_sphere(int *sign, t_menu *menu, t_sphere_obj *sphere)
{
	if (menu->select_data == 1)
		sphere->sp.pos.x += DIST * *sign;
	else if (menu->select_data == 2)
		sphere->sp.pos.y += DIST * *sign;
	else if (menu->select_data == 3)
		sphere->sp.pos.z += DIST * *sign;
	else if (menu->select_data == 4)
		obj_resize(&sphere->sp.r, sign);
}
