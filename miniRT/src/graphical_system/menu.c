/// @todo header

#include "minirt.h"

void	menu_obj_display(t_graph_sys *g_sys)
{
	mlx_color	color[7];
	int i;
	
	i = 0;
	while (i < 7)
		color[i++].rgba = 0xFFFFFFFF;
	if (g_sys->menu.select_obj != 0)
		color[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 15, color[0], OBJ_T);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 30, color[1], X_T);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 45, color[2], Y_T);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 60, color[3], Z_T);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 90, color[0], OBJ_R);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 105, color[4], X_R);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 120, color[5], Y_R);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 135, color[6], Z_R);
}

void	menu_light_display(t_graph_sys *g_sys)
{
	mlx_color	color[4];
	const char	*message[4] = {LGT_T, X_T, Y_T, Z_T};
	int			i;
	int			y;

	i = 0;
	y = 165;
	while (i < 4)
		color[i++].rgba = 0xFFFFFFFF;
	if (g_sys->menu.select_l != 0)
		color[g_sys->menu.select_data].rgba = 0x0000FFFF;
	i = 0;
	while (i < 4)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 1, y, color[i], (char *)message[i]);
		y += 15;
		i++;
	}
}

void	menu_management(t_graph_sys *g_sys)
{
	menu_obj_display(g_sys);
	menu_light_display(g_sys);
}