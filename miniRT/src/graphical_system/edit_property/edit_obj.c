/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:45:12 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:45:14 by tle-floc         ###   ########.fr       */
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
		obj_resize(&cone->co.h, sign);
	else if (menu->i_subsubmenu == 1)
		obj_resize(&cone->co.r, sign);
	else if (menu->i_subsubmenu <= 4)
		data_change_translation(&cone->co.pos, menu->i_subsubmenu - 2, sign);
	else if (menu->i_subsubmenu == 5)
		rotation_on_right(&cone->co.right, &cone->co.up, &cone->co.dir, sign);
	else if (menu->i_subsubmenu == 6)
		rotation_on_up(&cone->co.right, &cone->co.up, &cone->co.dir, sign);
	else if (menu->i_subsubmenu == 7)
		rotation_on_forward(&cone->co.right, &cone->co.up, &cone->co.dir, sign);
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
		rotation_on_right(&cylinder->cy.right, &cylinder->cy.up,
			&cylinder->cy.dir, sign);
	else if (menu->i_subsubmenu == 6)
		rotation_on_up(&cylinder->cy.right, &cylinder->cy.up,
			&cylinder->cy.dir, sign);
	else if (menu->i_subsubmenu == 7)
		rotation_on_forward(&cylinder->cy.right, &cylinder->cy.up,
			&cylinder->cy.dir, sign);
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
		rotation_on_right(&plane->right, &plane->up, &plane->pl.n, sign);
	else if (menu->i_subsubmenu == 2)
		rotation_on_up(&plane->right, &plane->up, &plane->pl.n, sign);
	else
		rotation_on_forward(&plane->right, &plane->up, &plane->pl.n, sign);
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
