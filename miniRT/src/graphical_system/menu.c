/// @todo header

#include "minirt.h"

void	menu_obj_display(t_scene *scene, t_graph_sys *g_sys)
{
	(void)scene;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 135, (mlx_color){ .rgba = 0xFFFFFFFF }, OBJ_T_POS);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 195, (mlx_color){ .rgba = 0xFFFFFFFF }, OBJ_T_DIR);
}

void	menu_light_display(t_scene *scene, t_graph_sys *g_sys)
{
	(void)scene;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 255, (mlx_color){ .rgba = 0xFFFFFFFF }, LGT_T_POS);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 315, (mlx_color){ .rgba = 0xFFFFFFFF }, LGT_T_DIR);
}

void	menu_cam_display(t_scene *scene, t_graph_sys *g_sys)
{
	(void)scene;
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 15, (mlx_color){ .rgba = 0xFFFFFFFF }, CAM_T_POS);
	mlx_string_put(g_sys->mlx, g_sys->win, 1, 75, (mlx_color){ .rgba = 0xFFFFFFFF }, CAM_T_DIR);
}
void	menu_management(t_scene *scene, t_graph_sys *g_sys)
{
	(void)scene;
	menu_cam_display(scene, g_sys);
	menu_obj_display(scene, g_sys);
	menu_light_display(scene, g_sys);
	
}