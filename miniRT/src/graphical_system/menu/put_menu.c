/// @todo header

#include "minirt.h"

/**
 * @brief Manage display of menu light.
 */
void	menu_light_display(t_graph_sys *g_sys)
{
	mlx_color	clr[4];
	const char	*text[4] = {LGT, X, Y, Z};
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 4)
		clr[i++].rgba = WHITE;
	clr[g_sys->menu.select_data].rgba = TEXT_COLOR;
	i = 0;
	while (i < 4)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[i], (char *)text[i]);
		y += 15;
		i++;
	}
}

/**
 * @brief Manage display of menu general.
 */
void	menu_selec_display(t_graph_sys *g_sys)
{
	mlx_color	clr;
	const char	*text[3] = {M, M_O, M_L};
	int			i;
	int			y;

	i = 0;
	y = 15;
	clr.rgba = WHITE;
	while (i < 3)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr, (char *)text[i]);
		y += 15;
		i++;
	}
}

/**
 * @brief Manage select display menu.
 */
void	menu_management(t_graph_sys *g_sys)
{
	mlx_put_image_to_window(g_sys->mlx, g_sys->win, g_sys->menu.background,
		0, 0);
	if (g_sys->menu.select_type == MENU_HANDLE)
		menu_selec_display(g_sys);
	else if (g_sys->menu.select_type == MENU_OBJ)
		menu_obj_display(g_sys);
	else if (g_sys->menu.select_type == MENU_LIGHT)
		menu_light_display(g_sys);
}
