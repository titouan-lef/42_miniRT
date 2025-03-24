/// @todo header

#include "minirt.h"

static void	clean_graph_sys(t_graph_sys *graph_sys)
{
	mlx_destroy_window(graph_sys->mlx, graph_sys->win);
	mlx_destroy_image(graph_sys->mlx, graph_sys->back_buffer);
	mlx_destroy_image(graph_sys->mlx, graph_sys->front_buffer);
	mlx_destroy_context(graph_sys->mlx);
}

static int	init_buffers(t_graph_sys *graph_sys)
{
	graph_sys->back_buffer = mlx_new_image(graph_sys->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (graph_sys->back_buffer == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_BACK_BUFFER_INIT);
		return (1);
	}
	graph_sys->front_buffer = mlx_new_image(graph_sys->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (graph_sys->front_buffer == MLX_NULL_HANDLE)
	{
		mlx_destroy_image(graph_sys->mlx, graph_sys->back_buffer);
		ft_putendl_error(ERR_FRONT_BUFFER_INIT);
		return (1);
	}
	return (0);
}

static int	init_mlx(t_graph_sys *graph_sys)
{
	graph_sys->mlx = mlx_init();
	if (graph_sys->mlx == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_MLX_INIT);
		return (1);
	}
	return (0);
}

static int	init_graphical_data(t_graph_sys *graph_sys)
{
	if (init_mlx(graph_sys))
		return (1);
	mlx_set_fps_goal(graph_sys->mlx, 60);
	if (init_buffers(graph_sys))
	{
		mlx_destroy_context(graph_sys->mlx);
		return (1);
	}
	if (init_window(graph_sys))
	{
		mlx_destroy_image(graph_sys->mlx, graph_sys->back_buffer);
		mlx_destroy_image(graph_sys->mlx, graph_sys->front_buffer);
		mlx_destroy_context(graph_sys->mlx);
		return (1);
	}
	return (0);
}

/*static void update(void* param)
{
	t_graph_sys	*graph_sys;

	graph_sys = (t_graph_sys *) param;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j)
			set_image_pixel(graph_sys, i, j, ft_color_create(255, 0, 255, 0));
	}
	put_image_to_win(graph_sys);
}*/

int	manage_graphical_system(void)
{
	t_graph_sys	graph_sys;

	if (init_graphical_data(&graph_sys))
		return (1);
	on_event(&graph_sys);
	//mlx_add_loop_hook(graph_sys.mlx, update, &graph_sys);
	mlx_loop(graph_sys.mlx);
	clean_graph_sys(&graph_sys);
	return (0);
}
