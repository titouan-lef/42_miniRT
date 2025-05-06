/// @todo header

#include "minirt.h"

/**
 * @brief Defile the value with a start, end and increment.
 */
void	defile(size_t *position, int end, int move)
{
	int	new;

	new = *position + move;
	if (new < 0)
		*position = end;
	else if (new > end)
		*position = 0;
	else
		*position = new;
}

void	reset_menu(t_menu *menu)
{
	menu->i_submenu = 0;
	menu->i_subsubmenu = 0;
}

/**
 * @brief Init all value of struct menu.
 */
int	init_menu(t_graph_sys *g_sys)
{
	const mlx_color	color = {.rgba = MENU_COLOR};
	int				x;
	int				y;

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
	g_sys->menu.option = MENU_DISABLE;
	reset_menu(&g_sys->menu);
	return (0);
}
