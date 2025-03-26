/// @todo header

#include "minirt.h"

/**
 * @brief Put the current image in window.
 * @details The back and front buffer are swapped.
 * New image put in the window.
 */
void	put_image_to_win(t_graph_sys *graph_sys)
{
	const mlx_color	mlx_black = {.rgba = 0x000000FF};

	swap_buffer(&graph_sys->buff);
	mlx_clear_window(graph_sys->mlx, graph_sys->win, mlx_black);
	mlx_put_image_to_window(graph_sys->mlx, graph_sys->win,
		*graph_sys->buff.front, 0, 0);
}

void	set_image_pixel(t_graph_sys *graph_sys, int x, int y, t_color c)
{
	mlx_color	color;

	color.rgba = ft_get_rgba(c);
	mlx_set_image_pixel(graph_sys->mlx, *graph_sys->buff.back, x, y, color);
}
