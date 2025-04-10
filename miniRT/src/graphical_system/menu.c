/// @todo header

#include "minirt.h"

static void	put_menu(t_graph_sys *g_sys, const char **text)
{
	mlx_color	clr[4];
	int			i;
	int			y;

	i = 0;
	y = 15;
	while (i < 4)
		clr[i++].rgba = 0xFFFFFFFF;
	if (g_sys->menu.select_obj != 0)
		clr[g_sys->menu.select_data].rgba = 0x0000FFFF;
	i = 0;
	while (i < 4)
	{
		mlx_string_put(g_sys->mlx, g_sys->win, 1, y, clr[i], (char *)text[i]);
		y += 15;
		i++;
	}
}

void	menu_obj_display(t_graph_sys *g_sys)
{
	const char	*translation[4] = {OBJ_T, X_T, Y_T, Z_T};
	const char	*rotate[4] = {OBJ_R, X_R, Y_R, Z_R};
	
	if (g_sys->menu.select_rotation !=0)
		put_menu(g_sys, rotate);
	else 
		put_menu(g_sys, translation);	
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
	sprintf(chaine, "%f", g_sys->menu.cam_dir->x);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 60, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam_dir->y);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 75, clr, chaine);//debug
	sprintf(chaine, "%f", g_sys->menu.cam_dir->z);//debug
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 90, clr, chaine);//debug
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
