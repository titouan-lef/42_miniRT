/// @todo header

#include "minirt.h"

int	init_mlx(t_graph_sys *graph_sys)
{
	graph_sys->mlx = mlx_init();
	if (graph_sys->mlx == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_MLX_INIT);
		return (1);
	}
	return (0);
}

int	init_graphical_data(t_graph_sys *graph_sys)
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

void	clean_graph_sys(t_graph_sys *graph_sys)
{
	mlx_destroy_window(graph_sys->mlx, graph_sys->win);
	if (graph_sys->back_buffer)
		mlx_destroy_image(graph_sys->mlx, graph_sys->back_buffer);
	if (graph_sys->front_buffer)
		mlx_destroy_image(graph_sys->mlx, graph_sys->front_buffer);
	mlx_destroy_context(graph_sys->mlx);
}
