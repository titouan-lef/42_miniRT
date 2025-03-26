/// @todo header

#include "minirt.h"

static void	key_hook(int key, void *param)
{
	mlx_context	mlx;

	mlx = (mlx_context)param;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(mlx);
}

static void	key_hook_cam(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	camera_translation(scene, key);
	camera_rotation(scene, key);
}

static void	window_hook(int event, void *param)
{
	if (event == WIN_CLOSE)
		mlx_loop_end((mlx_context)param);
}

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
	keydown_event(scene);
}
