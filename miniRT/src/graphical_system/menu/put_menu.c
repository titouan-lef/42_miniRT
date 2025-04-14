/// @todo header

#include "minirt.h"

static void	put_menu_sphere(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_SP, X, Y, Z};
	const char	*resize[4] = {OBJ_SP, D, " ", " "};

	if (g_sys->menu.select_resize != 0)
		put_menu(g_sys, resize);
	else
		put_menu(g_sys, translation);
}

static void	put_menu_plane(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_PL, X, Y, Z};
	const char	*rotate[4] = {OBJ_PL, X, Y, Z};

	if (g_sys->menu.select_rotation != 0)
		put_menu(g_sys, rotate);
	else
		put_menu(g_sys, translation);
}

static void	put_menu_cylinder(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_CY, X, Y, Z};
	const char	*rotate[4] = {OBJ_CY, X, Y, Z};
	const char	*resize[4] = {OBJ_CY, D, H, " "};

	if (g_sys->menu.select_rotation != 0)
		put_menu(g_sys, rotate);
	else if (g_sys->menu.select_resize != 0)
		put_menu(g_sys, resize);
	else
		put_menu(g_sys, translation);
}

static void	put_menu_cone(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_CO, X, Y, Z};
	const char	*rotate[4] = {OBJ_CO, X, Y, Z};
	const char	*resize[4] = {OBJ_CO, D, H, " "};

	if (g_sys->menu.select_rotation != 0)
		put_menu(g_sys, rotate);
	else if (g_sys->menu.select_resize != 0)
		put_menu(g_sys, resize);
	else
		put_menu(g_sys, translation);
}

/**
 * @brief Manage display of menu obj
 */
void	menu_obj_display(t_graph_sys *g_sys)
{
	if (g_sys->menu.obj->type == SPHERE)
		put_menu_sphere(g_sys);
	else if (g_sys->menu.obj->type == CYLINDER)
		put_menu_cylinder(g_sys);
	else if (g_sys->menu.obj->type == CONE)
		put_menu_cone(g_sys);
	else
		put_menu_plane(g_sys);
}
