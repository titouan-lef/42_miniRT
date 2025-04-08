/// @todo header

#include "minirt.h"

static void	clean_graph_sys(t_graph_sys *g_sys)
{
	mlx_destroy_window(g_sys->mlx, g_sys->win);
	clean_double_buffer(g_sys);
	mlx_destroy_context(g_sys->mlx);
}

static int	init_mlx(t_graph_sys *g_sys)
{
	g_sys->mlx = mlx_init();
	if (g_sys->mlx == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_MLX_INIT);
		return (1);
	}
	return (0);
}

static int	init_graphical_data(t_graph_sys *g_sys)
{
	if (init_mlx(g_sys))
		return (1);
	if (init_double_buffer(g_sys))
	{
		mlx_destroy_context(g_sys->mlx);
		return (1);
	}
	mlx_set_fps_goal(g_sys->mlx, FPS);
	if (init_window(g_sys))
	{
		clean_double_buffer(g_sys);
		mlx_destroy_context(g_sys->mlx);
		return (1);
	}
	g_sys->menu_enable = 0;
	g_sys->def_h = 1;
	g_sys->def_w = 1;
	return (0);
}

static void	update(void *param)
{
	t_scene		*scene;
	t_graph_sys	*g_sys;
	int			result;

	scene = (t_scene *) param;
	g_sys = &scene->g_sys;
	mouse_event(scene, g_sys);
	init_calculation(&scene->cam.pos, scene->lst_obj);
	result = ray_lauch_test(scene);
	put_image_to_win(&scene->g_sys);
	if (g_sys->menu_enable != 0)
		menu_management(scene, g_sys);
}

int	manage_graphical_system(t_scene	*scene)
{
	if (init_graphical_data(&scene->g_sys))
		return (1);
	mlx_mouse_move(scene->g_sys.mlx, scene->g_sys.win, WIN_HW, WIN_HH);
	on_event(scene);
	mlx_add_loop_hook(scene->g_sys.mlx, update, scene);
	mlx_loop(scene->g_sys.mlx);
	clean_graph_sys(&scene->g_sys);
	return (0);
}
