/// @todo header

#include "minirt.h"

void	put_menu_sphere(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_SP_T, X, Y, Z};
	const char	*resize[4] = {OBJ_SP_S, D, " ", " "};

	if (g_sys->menu.select_resize != 0)
		put_menu(g_sys, resize);
	else
		put_menu(g_sys, translation);
}

void	put_menu_plane(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_PL_T, X, Y, Z};
	const char	*rotate[4] = {OBJ_PL_R, X, Y, Z};

	if (g_sys->menu.select_rotation != 0)
		put_menu(g_sys, rotate);
	else
		put_menu(g_sys, translation);
}

void	put_menu_cylinder(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_CY_T, X, Y, Z};
	const char	*rotate[4] = {OBJ_CY_R, X, Y, Z};
	const char	*resize[4] = {OBJ_CY_S, D, H, " "};

	if (g_sys->menu.select_rotation != 0)
		put_menu(g_sys, rotate);
	else if (g_sys->menu.select_resize != 0)
		put_menu(g_sys, resize);
	else
		put_menu(g_sys, translation);
}

void	put_menu_cone(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_CO_T, X, Y, Z};
	const char	*rotate[4] = {OBJ_CO_R, X, Y, Z};
	const char	*resize[4] = {OBJ_CO_S, D, H, " "};

	if (g_sys->menu.select_rotation != 0)
		put_menu(g_sys, rotate);
	else if (g_sys->menu.select_resize != 0)
		put_menu(g_sys, resize);
	else
		put_menu(g_sys, translation);
}

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
