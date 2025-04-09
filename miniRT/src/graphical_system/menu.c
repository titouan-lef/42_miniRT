/// @todo header

#include "minirt.h"

void	menu_obj_display(t_scene *scene, t_graph_sys *g_sys)
{
	mlx_color	color[7];
	int i;
	
	(void)scene;
	i = 0;
	while (i < 7)
		color[i++].rgba = 0xFFFFFFFF;
	if (g_sys->menu.select_obj != 0)
		color[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 135, color[0], OBJ_T_POS);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 150, color[1], "x:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 165, color[2], "y:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 180, color[3], "z:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 195, color[0], OBJ_T_DIR);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 210, color[4], "x:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 225, color[5], "y:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 240, color[6], "z:");
}

void	menu_light_display(t_scene *scene, t_graph_sys *g_sys)
{
	mlx_color	color[4];
	int i;
	
	(void)scene;
	i = 0;
	while (i < 4)
		color[i++].rgba = 0xFFFFFFFF;
	if (g_sys->menu.select_l != 0)
		color[g_sys->menu.select_data].rgba = 0x0000FFFF;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 255, color[0], LGT_T_POS);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 270, color[1], "x:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 285, color[2], "y:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 300, color[3], "z:");
}

void	menu_cam_display(t_scene *scene, t_graph_sys *g_sys)
{
	(void)scene;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 15, (mlx_color){ .rgba = 0xFFFFFFFF }, CAM_T_POS);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 30, (mlx_color){ .rgba = 0xFFFFFFFF }, "x:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 45, (mlx_color){ .rgba = 0xFFFFFFFF }, "y:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 60, (mlx_color){ .rgba = 0xFFFFFFFF }, "z:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 75, (mlx_color){ .rgba = 0xFFFFFFFF }, CAM_T_DIR);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 90, (mlx_color){ .rgba = 0xFFFFFFFF }, "x:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 105, (mlx_color){ .rgba = 0xFFFFFFFF }, "y:");
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 120, (mlx_color){ .rgba = 0xFFFFFFFF }, "z:");
}
void	menu_management(t_scene *scene, t_graph_sys *g_sys)
{
	(void)scene;
	menu_cam_display(scene, g_sys);
	menu_obj_display(scene, g_sys);
	menu_light_display(scene, g_sys);
	
}