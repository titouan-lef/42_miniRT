/// @todo header

#include "minirt.h"

static void	swap_buffer(t_graph_sys *graph_sys)
{
	mlx_image	tmp;

	tmp = graph_sys->back_buffer;
	graph_sys->back_buffer = graph_sys->front_buffer;
	graph_sys->front_buffer = tmp;
}

int	put_image_to_win(t_graph_sys *graph_sys)
{
	swap_buffer(graph_sys);
	mlx_destroy_image(graph_sys->mlx, graph_sys->back_buffer);
	mlx_put_image_to_window(graph_sys->mlx, graph_sys->win, graph_sys->front_buffer, 0, 0);
	graph_sys->back_buffer = mlx_new_image(graph_sys->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (graph_sys->back_buffer == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_BACK_BUFFER_INIT);
		return (1);
	}
	return (0);
}

void	set_image_pixel(t_graph_sys *graph_sys, int x, int y, t_color c)
{
	mlx_color	color;

	(void) c;
	color.rgba = 0xFF0000FF;//ft_create_argb(c);
	mlx_set_image_pixel(graph_sys->mlx, graph_sys->back_buffer, x, y, color);
}
