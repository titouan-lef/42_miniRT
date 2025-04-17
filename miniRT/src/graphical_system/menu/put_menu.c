/// @todo header

#include "minirt.h"

static void	put_menu_sphere(t_graph_sys *g_sys)
{
	const char	*txt[6] = {OBJ_SP, T, X, Y, Z, D};
	mlx_color	clr[5];
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 5)
		clr[i++].rgba = 0xFFFFFFFF;
	clr[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[0], (char *)txt[0]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 15, clr[0], (char *)txt[1]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 30, clr[1], (char *)txt[2]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 45, clr[2], (char *)txt[3]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 60, clr[3], (char *)txt[4]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 75, clr[4], (char *)txt[5]);
}

static void	put_menu_plane(t_graph_sys *g_sys)
{
	const char	*txt[6] = {OBJ_PL, T, R, X, Y, Z};
	mlx_color	clr[5];
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 5)
		clr[i++].rgba = 0xFFFFFFFF;
	clr[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[0], (char *)txt[0]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 15, clr[1], (char *)txt[1]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 30, clr[0], (char *)txt[2]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 45, clr[2], (char *)txt[3]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 60, clr[3], (char *)txt[4]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 75, clr[4], (char *)txt[5]);
}

static void	put_menu_cylinder(t_graph_sys *g_sys)
{
	const char	*txt[11] = {OBJ_CY, T, X, Y, Z, R, X, Y, Z, D, H};
	mlx_color	clr[9];
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 9)
		clr[i++].rgba = 0xFFFFFFFF;
	clr[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[0], (char *)txt[0]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 15, clr[0], (char *)txt[1]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 30, clr[1], (char *)txt[2]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 45, clr[2], (char *)txt[3]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 60, clr[3], (char *)txt[4]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 75, clr[0], (char *)txt[5]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 90, clr[4], (char *)txt[6]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 105, clr[5], (char *)txt[7]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 120, clr[6], (char *)txt[8]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 135, clr[7], (char *)txt[9]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 150, clr[8], (char *)txt[10]);
}

static void	put_menu_cone(t_graph_sys *g_sys)
{
	const char	*txt[11] = {OBJ_CO, T, X, Y, Z, R, X, Y, Z, D, H};
	mlx_color	clr[9];
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 9)
		clr[i++].rgba = 0xFFFFFFFF;
	clr[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[0], (char *)txt[0]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 15, clr[0], (char *)txt[1]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 30, clr[1], (char *)txt[2]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 45, clr[2], (char *)txt[3]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 60, clr[3], (char *)txt[4]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 75, clr[0], (char *)txt[5]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 90, clr[4], (char *)txt[6]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 105, clr[5], (char *)txt[7]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 120, clr[6], (char *)txt[8]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 135, clr[7], (char *)txt[9]);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, y + 150, clr[8], (char *)txt[10]);
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
