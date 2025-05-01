/// @todo header

#include "minirt.h"

/**
 * @brief Put the current image in window.
 * @details The back and front buffer are swapped.
 * New image put in the window.
 */
void	put_image_to_win(t_graph_sys *g_sys)
{
	const mlx_color	mlx_black = {.rgba = BLACK};

	swap_buffer(&g_sys->buff);
	mlx_clear_window(g_sys->mlx, g_sys->win, mlx_black);
	mlx_put_image_to_window(g_sys->mlx, g_sys->win,
		*g_sys->buff.front, 0, 0);
}

void	set_image_pixel(t_graph_sys *g_sys, int x, int y, t_color c)
{
	mlx_color	color;
	int			i;
	int			j;

	i = 0;
	color.rgba = ft_get_rgba(c);
	while (i < g_sys->def_h)
	{
		j = 0;
		while (j < g_sys->def_w)
		{
			mlx_set_image_pixel(g_sys->mlx, *g_sys->buff.back, x + j, y + i,
				color);
			j++;
		}
		i++;
	}
}
