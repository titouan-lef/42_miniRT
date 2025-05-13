/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:45:12 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/13 12:07:43 by pchalmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Change the size of object.
 */
static void	obj_resize(double *r, int sign)
{
	double	new;

	new = *r + DIST * sign;
	if (new > 0)
		*r = new;
}

/**
 * @brief Edit the cone settings selected in the menu.
 * @details Modifiable data include position, orientation,
 * radius size and height size.
 */
void	edit_cone(int sign, t_menu *menu, t_cone_obj *cone)
{
	if (menu->i_subsubmenu == 0)
		obj_resize(&cone->co.r, sign);
	else if (menu->i_subsubmenu == 1)
		obj_resize(&cone->co.h, sign);
	else if (menu->i_subsubmenu <= 4)
		data_change_translation(&cone->co.pos, menu->i_subsubmenu - 2, sign);
	else if (menu->i_subsubmenu == 5)
		rotation_on_right(&cone->co.dir, &cone->co.right, &cone->co.up, sign);
	else if (menu->i_subsubmenu == 6)
		rotation_on_up(&cone->co.dir, &cone->co.right, &cone->co.up, sign);
	else if (menu->i_subsubmenu == 7)
		rotation_on_forward(&cone->co.dir, &cone->co.right, &cone->co.up, sign);
}

/**
 * @brief Edit the cylinder settings selected in the menu.
 * @details Modifiable data include position, orientation,
 * radius size and height size.
 */
void	edit_cylinder(int sign, t_menu *menu, t_cylinder_obj *cylinder)
{
	if (menu->i_subsubmenu == 0)
		obj_resize(&cylinder->cy.r, sign);
	else if (menu->i_subsubmenu == 1)
		obj_resize(&cylinder->cy.hh, sign);
	else if (menu->i_subsubmenu <= 4)
		data_change_translation(&cylinder->cy.pos, menu->i_subsubmenu - 2,
			sign);
	else if (menu->i_subsubmenu == 5)
		rotation_on_right(&cylinder->cy.dir, &cylinder->cy.right,
			&cylinder->cy.up, sign);
	else if (menu->i_subsubmenu == 6)
		rotation_on_up(&cylinder->cy.dir, &cylinder->cy.right,
			&cylinder->cy.up, sign);
	else if (menu->i_subsubmenu == 7)
		rotation_on_forward(&cylinder->cy.dir, &cylinder->cy.right,
			&cylinder->cy.up, sign);
}

/**
 * @brief Edit the plane settings selected in the menu.
 * @details Modifiable data include orientation and position plane.
 */
void	edit_plane(int sign, t_menu *menu, t_plane_obj *plane)
{
	if (menu->i_subsubmenu == 0)
		plane->pl.d += DIST * sign;
	else if (menu->i_subsubmenu == 1)
		rotation_on_right(&plane->pl.n, &plane->right, &plane->up, sign);
	else if (menu->i_subsubmenu == 2)
		rotation_on_up(&plane->pl.n, &plane->right, &plane->up, sign);
	else
		rotation_on_forward(&plane->pl.n, &plane->right, &plane->up, sign);
}

/**
 * @brief Edit the sphere settings selected in the menu.
 * @details Modifiable data include radius size and sphere position.
 */
void	edit_sphere(int sign, t_menu *menu, t_sphere_obj *sphere)
{
	if (menu->i_subsubmenu == 0)
		obj_resize(&sphere->sp.r, sign);
	else
		data_change_translation(&sphere->sp.pos, menu->i_subsubmenu - 1, sign);
}
