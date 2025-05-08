/// @todo header

#include "minirt.h"

/**
 * @brief Init mlx_context 
 * @return 1 if mlx_init failed.
 */
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

/**
 * @brief Init all display environemnt 
 * @return 1 if init_mlx or init_double_buffer init_window or init_menu failed.
 */
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
	if (init_menu(g_sys))
	{
		clean_mlx_sys(g_sys);
		return (1);
	}
	g_sys->def_h = 1;
	g_sys->def_w = 1;
	return (0);
}

static void	update(void *param)
{
	t_scene		*scene;
	t_graph_sys	*g_sys;

	scene = (t_scene *) param;
	g_sys = &scene->g_sys;
	if (g_sys->menu.mouse_is_hide == 1)
		mouse_event(scene, g_sys);
	init_calculation(&scene->cam.pos, scene->tab_obj);
	ray_lauch(scene);
	put_image_to_win(&scene->g_sys);
	if (g_sys->menu.option != MENU_DISABLE)
		menu_management(scene);
}

/**
 * @brief Manages program display, graphics rendering,
 * keyboard and mouse management.
 * @return 1 if init_grraphical_data or init_all_texture failed.
 */
int	manage_graphical_system(t_scene	*scene)
{
	if (init_graphical_data(&scene->g_sys))
		return (1);
	if (init_all_texture(scene->tab_obj, scene->g_sys.mlx))
	{
		mlx_destroy_image(scene->g_sys.mlx, scene->g_sys.menu.background);
		clean_mlx_sys(&scene->g_sys);
		return (1);
	}
	mlx_mouse_move(scene->g_sys.mlx, scene->g_sys.win, WIN_HW, WIN_HH);
	on_event(scene);
	mlx_add_loop_hook(scene->g_sys.mlx, update, scene);
	mlx_loop(scene->g_sys.mlx);
	clean_graph_sys(scene, &scene->g_sys);
	return (0);
}
