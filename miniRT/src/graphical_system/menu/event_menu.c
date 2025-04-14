/// @todo header

#include "minirt.h"

/**
 * @brief When you press M menu open if you press again M menu close.
 * if menu is open you can press O for open menu obj and L for open menu liight.
 * if you press again on O or L the menu obj or menu light close
 */
static void	key_hook_menu_handle(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (key == SDL_SCANCODE_M)
		menu->enable = 1 - menu->enable;
	if (menu->enable == 0)
	{
		init_menu(menu);
		return ;
	}
	if (key == SDL_SCANCODE_O)
	{
		menu->select_obj = 1 - menu->select_obj;
		if (menu->select_l == 1)
			menu->select_l = 1 - menu->select_l;
		menu->select_data = 1;
	}
	else if (key == SDL_SCANCODE_L)
	{
		menu->select_l = 1 - menu->select_l;
		if (menu->select_obj == 1)
			menu->select_obj = 1 - menu->select_obj;
		menu->select_data = 1;
	}
}

/**
 * @brief when the menu obj you can press N for select the next obj
 */
static void	key_hook_select_obj(int key, void *param)
{
	static size_t	i;
	t_scene			*scene;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.select_obj == 0)
	{
		i = 0;
		return ;
	}
	scene->g_sys.menu.obj = scene->tab_obj[i];
	if (key == SDL_SCANCODE_N)
	{
		if (scene->g_sys.menu.select_obj != 0)
			++i;
		if (scene->tab_obj[i] == NULL)
			i = 0;
	}
}

/**
 * @brief when the menu light you can press N for select the next light
 */
static void	key_hook_select_light(int key, void *param)
{
	static size_t	i;
	t_scene			*scene;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.select_l == 0)
	{
		i = 0;
		return ;
	}
	scene->g_sys.menu.light = scene->tab_l[i];
	if (key == SDL_SCANCODE_N)
	{
		if (scene->g_sys.menu.select_l != 0)
			++i;
		if (scene->tab_l[i] == NULL)
			i = 0;
	}
}

/**
 * @brief when the menu obj or menu light is open you can press up arrow or
 * down arrow for selec a paam you want to change.
 * If you press R or H you change type o data is change.
 * R for rotation.
 * H for size.
 */
void	key_hook_select_change(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (key == SDL_SCANCODE_UP)
		defile(&menu->select_data, 1, 3, -1);
	if (key == SDL_SCANCODE_DOWN)
		defile(&menu->select_data, 1, 3, 1);
	if (key == SDL_SCANCODE_R)
	{
		menu->select_rotation = 1 - menu->select_rotation;
		if (menu->select_resize == 1)
			menu->select_resize = 1 - menu->select_resize;
	}
	if (key == SDL_SCANCODE_H)
	{
		menu->select_resize = 1 - menu->select_resize;
		if (menu->select_rotation == 1)
			menu->select_rotation = 1 - menu->select_rotation;
	}
}

void	menu_event(t_scene *scene)
{
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_menu_handle, &scene->g_sys.menu);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_obj, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_light, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		data_change, &scene->g_sys.menu);
}
