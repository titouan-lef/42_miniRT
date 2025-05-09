/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-floc <tle-floc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:45:26 by tle-floc          #+#    #+#             */
/*   Updated: 2025/05/09 16:45:31 by tle-floc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief When you press M menu open if you press again M menu close.
 * If menu is open you can press O for open menu obj and L for open menu light.
 * If you press again on O or L the menu obj or menu light close.
 */
static void	key_hook_menu_handle(int key, void *param)
{
	t_menu			*menu;
	t_menu_option	option;

	if (key == SDL_SCANCODE_M)
		option = MENU_DISABLE;
	else if (key == SDL_SCANCODE_O)
		option = MENU_OBJ;
	else if (key == SDL_SCANCODE_L)
		option = MENU_LIGHT;
	else
		return ;
	menu = (t_menu *)param;
	if (menu->option == option)
	{
		menu->option = MENU_HANDLE;
		return ;
	}
	if (option != MENU_DISABLE)
		reset_menu(menu);
	menu->option = option;
}

static void	key_hook_select(int key, t_menu	*menu, void **tab)
{
	if (key != SDL_SCANCODE_N)
		return ;
	menu->i_subsubmenu = 0;
	if (tab[menu->i_submenu + 1] == NULL)
		menu->i_submenu = 0;
	else
		++menu->i_submenu;
}

/**
 * @brief When the menu obj you can press N for select the next obj.
 */
static void	key_hook_select_obj(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.option == MENU_OBJ)
		key_hook_select(key, &scene->g_sys.menu, (void **)scene->tab_obj);
}

/**
 * @brief When the menu light you can press N for select the next light.
 */
static void	key_hook_select_light(int key, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.option == MENU_LIGHT)
		key_hook_select(key, &scene->g_sys.menu, (void **)scene->tab_l);
}

/**
 * @brief When the menu obj or menu light is open you can press up or down
 * arrow to navigate in menu or press left or right arrow to change value.
 */
void	menu_event(t_scene *scene)
{
	t_menu	*menu;

	menu = &scene->g_sys.menu;
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_menu_handle, menu);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_obj, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_light, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYDOWN,
		key_hook_select_change, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYDOWN,
		data_change, scene);
}
