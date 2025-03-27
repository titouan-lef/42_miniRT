/// @todo header

#include "minirt.h"

static void	key_hook(int key, void *param)
{
	mlx_context	mlx;

	mlx = (mlx_context)param;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(mlx);
}

static void	window_hook(int event, void *param)
{
	if (event == WIN_CLOSE)
		mlx_loop_end((mlx_context)param);
}

/**
 * @brief Manage full screen with F11
 * @details When you press F11 the window pass in full mode 
 * if you repress window repasse in normal mode
 */
static void	key_hook_fwin(int key, void *param)
{
	static int	fullscreen = 0;
	t_graph_sys	*mlx;

	mlx = (t_graph_sys *)param;
	if (key == SDL_SCANCODE_F11)
	{
		fullscreen = 1 - fullscreen;
		mlx_set_window_fullscreen(mlx->mlx, mlx->win, fullscreen);
	}
}

/**
 * @brief Manage all enevnt with KEYDOWN
 * @details key_hook is for close window with escape
 * key_hook_cam is for translation camera
 */
static void	keydown_event(t_scene *scene)
{
	t_graph_sys	*graph_sys;

	graph_sys = &scene->graph_sys;
	mlx_on_event(graph_sys->mlx, graph_sys->win, MLX_KEYDOWN, key_hook,
		graph_sys->mlx);
	mlx_on_event(graph_sys->mlx, graph_sys->win, MLX_KEYDOWN, key_hook_cam,
		scene);
}

void	on_event(t_scene *scene)
{
	t_graph_sys	*graph_sys;

	graph_sys = &scene->graph_sys;
	mlx_on_event(graph_sys->mlx, graph_sys->win, MLX_WINDOW_EVENT, window_hook,
		graph_sys->mlx);
	mlx_on_event(graph_sys->mlx, graph_sys->win, MLX_KEYUP, key_hook_fwin,
		&scene->graph_sys);
	keydown_event(scene);
}
