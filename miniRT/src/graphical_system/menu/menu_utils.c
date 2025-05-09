/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:45:35 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:45:37 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Fill background image for menu display with pixel's color defined
 * in MENU_COLOR.
 */
static void	fill_background(t_graph_sys *g_sys)
{
	const mlx_color	color = {.rgba = MENU_COLOR};
	int				x;
	int				y;

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
}

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
	g_sys->menu.background = mlx_new_image(g_sys->mlx, MENU_W, MENU_H);
	if (g_sys->menu.background == MLX_NULL_HANDLE)
	{
		ft_putendl_error(ERR_MENU_INIT);
		return (1);
	}
	fill_background(g_sys);
	reset_menu(&g_sys->menu);
	g_sys->menu.option = MENU_DISABLE;
	g_sys->menu.mouse_is_hide = 0;
	return (0);
}
