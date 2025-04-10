/// @todo header

#include "minirt.h"

void	menu_obj_display(t_graph_sys *g_sys)
{
	mlx_color	color[7];
	int			i;

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
	mlx_color	clr[4];
	const char	*text[4] = {LGT_T, X_T, Y_T, Z_T};
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 4)
		clr[i++].rgba = 0xFFFFFFFF;
	if (g_sys->menu.select_l != 0)
		clr[g_sys->menu.select_data].rgba = 0x0000FFFF;
	i = 0;
	while (i < 4)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[i], (char *)text[i]);
		y += 15;
		i++;
	}
}

void	menu_selec_display(t_graph_sys *g_sys)
{
	mlx_color	clr;
	const char	*text[3] = {M, M_O, M_L};
	int			i;
	int			y;

	i = 0;
	y = 15;
	clr.rgba = 0xFFFFFFFF;
	while (i < 3)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr, (char *)text[i]);
		y += 15;
		i++;
	}
	char chaine[50];//debug
	sprintf(chaine, "%f", g_sys->menu.cam->dir.x);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 60, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam->dir.y);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 75, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam->dir.z);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 90, clr, chaine);//debug

	sprintf(chaine, "%f", g_sys->menu.cam->right.x);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 120, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam->right.y);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 135, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam->right.z);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 150, clr, chaine);//debug

	sprintf(chaine, "%f", g_sys->menu.cam->up.x);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 180, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam->up.y);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 195, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam->up.z);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 210, clr, chaine);//debug
}


void	menu_management(t_graph_sys *g_sys)
{
	if (g_sys->menu.select_l == 0 && g_sys->menu.select_obj == 0)
		menu_selec_display(g_sys);
	if (g_sys->menu.select_obj != 0)
		menu_obj_display(g_sys);
	else if (g_sys->menu.select_l != 0)
		menu_light_display(g_sys);
}
