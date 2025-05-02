/// @todo header

#include "minirt.h"

static void	put_menu_sphere(t_graph_sys *g_sys)
{
	const int	title_y[2] = {15, 45};
	const int	selection_y[4] = {30, 60, 75, 90};
	char		*title[2];
	char		*selection[4];

	title[0] = OBJ_SP;
	title[1] = T;
	selection[0] = D;
	selection[1] = X;
	selection[2] = Y;
	selection[3] = Z;
	put_menu_title(g_sys, title_y, title, 2);
	put_menu_selection(g_sys, selection_y, selection, 4);
}

static void	put_menu_plane(t_graph_sys *g_sys)
{
	const int	title_y[2] = {15, 45};
	const int	selection_y[4] = {30, 60, 75, 90};
	char		*title[2];
	char		*selection[4];

	title[0] = OBJ_PL;
	title[1] = R;
	selection[0] = T_PL;
	selection[1] = X;
	selection[2] = Y;
	selection[3] = Z;
	put_menu_title(g_sys, title_y, title, 2);
	put_menu_selection(g_sys, selection_y, selection, 4);
}

static void	put_menu_cylinder(t_graph_sys *g_sys)
{
	const int	title_y[3] = {15, 60, 120};
	const int	selection_y[8] = {30, 45, 75, 90, 105, 135, 150, 165};
	char		*title[3];
	char		*selection[8];

	title[0] = OBJ_CY;
	title[1] = T;
	title[2] = R;
	selection[0] = D;
	selection[1] = H;
	selection[2] = X;
	selection[3] = Y;
	selection[4] = Z;
	selection[5] = X;
	selection[6] = Y;
	selection[7] = Z;
	put_menu_title(g_sys, title_y, title, 3);
	put_menu_selection(g_sys, selection_y, selection, 8);
}

static void	put_menu_cone(t_graph_sys *g_sys)
{
	const int	title_y[3] = {15, 60, 120};
	const int	selection_y[8] = {30, 45, 75, 90, 105, 135, 150, 165};
	char		*title[3];
	char		*selection[8];

	title[0] = OBJ_CY;
	title[1] = T;
	title[2] = R;
	selection[0] = D;
	selection[1] = H;
	selection[2] = X;
	selection[3] = Y;
	selection[4] = Z;
	selection[5] = X;
	selection[6] = Y;
	selection[7] = Z;
	put_menu_title(g_sys, title_y, title, 3);
	put_menu_selection(g_sys, selection_y, selection, 8);
}

/**
 * @brief Manage display of menu obj.
 */
void	menu_obj_display(t_scene *scene)
{
	t_obj	*obj;

	obj = scene->tab_obj[scene->g_sys.menu.i_submenu];
	if (obj->type == SPHERE)
		put_menu_sphere(&scene->g_sys);
	else if (obj->type == CYLINDER)
		put_menu_cylinder(&scene->g_sys);
	else if (obj->type == CONE)
		put_menu_cone(&scene->g_sys);
	else
		put_menu_plane(&scene->g_sys);
}
