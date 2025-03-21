/// @todo header

#include "minirt.h"

static void	clean_graph_sys(t_graph_sys *graph_sys)
{
	mlx_destroy_window(graph_sys->mlx, graph_sys->win);
	if (graph_sys->back_buffer)
		mlx_destroy_image(graph_sys->mlx, graph_sys->back_buffer);
	if (graph_sys->front_buffer)
		mlx_destroy_image(graph_sys->mlx, graph_sys->front_buffer);
	mlx_destroy_context(graph_sys->mlx);
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
	graph_sys->back_buffer = NULL;
	graph_sys->front_buffer = NULL;
	if (init_mlx(graph_sys))
		return (1);
	mlx_set_fps_goal(graph_sys->mlx, 60);
	if (init_window(graph_sys))
	{
		mlx_destroy_context(graph_sys->mlx);
		return (1);
	}
	return (0);
}

int	manage_graphical_system(void)
{
	t_graph_sys	graph_sys;

	if (init_graphical_data(&graph_sys))
		return (1);
	on_event(&graph_sys);
	mlx_loop(graph_sys.mlx);
	clean_graph_sys(&graph_sys);
	return (0);
}
