/// @todo header

#include "minirt.h"

/**
 * @brief When you press M menu open if you press again M menu close.
 * If menu is open you can press O for open menu obj and L for open menu light.
 * If you press again on O or L the menu obj or menu light close.
 */
static void	key_hook_menu_handle(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (key == SDL_SCANCODE_M)
	{
		if (menu->select_type == MENU_DISABLE)
			menu->select_type = MENU_HANDLE;
		else
		{
			menu->select_type = MENU_DISABLE;
			reset_menu(menu);/** @todo useless because define in update() ? */
			return ;
		}
	}
	if (key == SDL_SCANCODE_O)
	{
		if (menu->select_type == MENU_OBJ)
			menu->select_type = MENU_HANDLE;
		else
			menu->select_type = MENU_OBJ;
	}
	else if (key == SDL_SCANCODE_L)
	{
		if (menu->select_type == MENU_LIGHT)
			menu->select_type = MENU_HANDLE;
		else
			menu->select_type = MENU_LIGHT;
	}
}

/**
 * @brief When the menu obj you can press N for select the next obj.
 */
static void	key_hook_select_obj(int key, void *param)
{
	static size_t	i;
	t_scene			*scene;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.select_type == MENU_HANDLE)
	{
		i = 0;
		return ;
	}
	scene->g_sys.menu.obj = scene->tab_obj[i];
	if (key == SDL_SCANCODE_N)
	{
		if (scene->g_sys.menu.select_type == MENU_OBJ)
			++i;
		if (scene->tab_obj[i] == NULL)
			i = 0;
	}
}

/**
 * @brief When the menu light you can press N for select the next light.
 */
static void	key_hook_select_light(int key, void *param)
{
	static size_t	i;/** @todo not initialized ? */
	t_scene			*scene;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.select_type != MENU_LIGHT)
	{
		i = 0;
		return ;
	}
	scene->g_sys.menu.light = scene->tab_l[i];
	if (key == SDL_SCANCODE_N)
	{
		if (scene->g_sys.menu.select_type == MENU_LIGHT)
			++i;
		if (scene->tab_l[i] == NULL)
			i = 0;
	}
}

/**
 * @brief When the menu obj or menu light is open you can press up or down
 * arrow to navigate in menu or press left or right arrow to change value.
 */
void	menu_event(t_scene *scene)
{
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_menu_handle, &scene->g_sys.menu);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_obj, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_light, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYDOWN,
		data_change, &scene->g_sys.menu);
}
