/// @todo header

#include "minirt.h"

static void	clean_graph_sys(t_graph_sys *graph_sys)
{
	mlx_destroy_window(graph_sys->mlx, graph_sys->win);
	clean_double_buffer(graph_sys);
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
	if (init_mlx(graph_sys))
		return (1);
	if (init_double_buffer(graph_sys))
	{
		mlx_destroy_context(graph_sys->mlx);
		return (1);
	}
	mlx_set_fps_goal(graph_sys->mlx, 60);
	if (init_window(graph_sys))
	{
		clean_double_buffer(graph_sys);
		mlx_destroy_context(graph_sys->mlx);
		return (1);
	}
	return (0);
}

static void	update(void *param)
{
	t_graph_sys	*graph_sys;

	graph_sys = (t_graph_sys *) param;
}

int	manage_graphical_system(void)
{
	t_graph_sys	graph_sys;

	if (init_graphical_data(&graph_sys))
		return (1);
	on_event(&graph_sys);
	mlx_add_loop_hook(graph_sys.mlx, update, &graph_sys);
	mlx_loop(graph_sys.mlx);
	clean_graph_sys(&graph_sys);
	return (0);
}
