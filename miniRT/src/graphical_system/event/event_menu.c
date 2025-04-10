/// @todo header

#include "minirt.h"

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

void	key_hook_select_moov(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (key == SDL_SCANCODE_R)
		menu->select_rotation = 1 - menu->select_rotation;
}

static void	key_hook_menu_defile(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (key == SDL_SCANCODE_UP)
		defile(&menu->select_data, 1, 3, -1);
	else if (key == SDL_SCANCODE_DOWN)
		defile(&menu->select_data, 1, 3, 1);
}

static void	key_hook_select_obj(int key, void *param)
{
	t_scene			*scene;
	static t_list	*obj_next;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.select_obj == 0)
	{
		obj_next = scene->lst_obj;
		return ;
	}
	scene->g_sys.menu.obj = (t_obj *)obj_next->content;
	if (key == SDL_SCANCODE_N)
	{
		if (scene->g_sys.menu.select_obj != 0)
			obj_next = obj_next->next;
		if (obj_next == NULL)
			obj_next = scene->lst_obj;
	}
}

static void	key_hook_select_light(int key, void *param)
{
	t_scene			*scene;
	static t_list	*next;

	scene = (t_scene *)param;
	if (scene->g_sys.menu.select_l == 0)
	{
		next = scene->lst_light;
		return ;
	}
	scene->g_sys.menu.light = (t_light *)next->content;
	if (key == SDL_SCANCODE_N)
	{
		if (scene->g_sys.menu.select_l != 0)
			next = next->next;
		if (next == NULL)
			next = scene->lst_light;
		scene->g_sys.menu.light = (t_light *)next->content;
	}
}
void	data_change(int key, void *param)
{
	t_menu	*menu;

	menu = (t_menu *)param;
	if (menu->select_l != 0)
	{
		key_hook_light_translation(key, param);
	}
	if (menu->select_obj != 0)
	{
		key_hook_select_moov(key, param);
		if (menu->select_rotation != 0)
			key_hook_obj_rotation(key, param);
		else
			key_hook_obj_translation(key, param);
	}
}

void	menu_event(t_scene *scene)
{
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_menu_handle, &scene->g_sys.menu);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_menu_defile, &scene->g_sys.menu);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_obj, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		key_hook_select_light, scene);
	mlx_on_event(scene->g_sys.mlx, scene->g_sys.win, MLX_KEYUP,
		data_change, &scene->g_sys.menu);
}
