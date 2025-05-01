/// @todo header

#include "minirt.h"

/**
 * @brief Defile the value with a start, end and increment.
 */
void	defile(int *position, int start, int end, int moov)
{
	*position += moov;
	if (*position > end)
		*position = start;
	if (*position < start)
		*position = end;
}

void	reset_menu(t_menu *menu)
{
	menu->select_type = 0;
	menu->select_data = 1;
}

/**
 * @brief Init all value of struct menu.
 */
int	init_menu(t_graph_sys *g_sys)
{
	const mlx_color	color = {.rgba = MENU_COLOR};
	int				x;
	int				y;

	g_sys->menu.enable = 0;
	reset_menu(&g_sys->menu);
	g_sys->menu.background = mlx_new_image(g_sys->mlx, MENU_W, MENU_H);
	if (g_sys->menu.background == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_MENU_INIT);
		return (1);
	}
	x = 0;
	while (x < MENU_W)
	{
		y = 0;
		while (y < MENU_H)
		{
			mlx_set_image_pixel(g_sys->mlx, g_sys->menu.background,
				x, y, color);
			++y;
		}
		++x;
	}
	return (0);
}
